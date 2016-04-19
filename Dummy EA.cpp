//
//  Dummy EA.cpp
//  Controller
//
//  Created by Scott Forer on 11/19/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#include "Dummy EA.hpp"

//-----------------------------------------------------------------------------------------------------------------------------
//Target Controls Assignment
//creates target control vector
void Dummy_EA::create_target_controls()
{
    target_controls.push_back(control_one);
    target_controls.push_back(control_two);
//    cout << "Target Controls" << endl;
//    cout << target_controls.size() << endl;
//    for (int j = 0; j < target_controls.size(); j++)
//    {
//        cout << target_controls.at(j) << endl;
//    }
//    cout << "\n" << endl;
}


//Population Generator
//Controls the creation of the population
void Dummy_EA::build_population(int sim_number_state_variable_inputs, int sim_hidden_layer_size, int sim_number_controls)
{
    Population.clear();
    for (int h  = 0; h < pop_size; h++)
    {
        Individual PM;
        //create the weights
        PM.create_weights(sim_number_state_variable_inputs, sim_hidden_layer_size, sim_number_controls);
        Population.push_back(PM);

    }
}


//-----------------------------------------------------------------------------------------------------------------------------
//Fitness Calculator
//calculates the fitness for each control and the total fitness
void Dummy_EA::get_error(double &total_control_value, double &total_error, vector<double> &sim_state_variable_inputs)
{
    //cout << controls_for_population.size() << endl;
    //calculates the fitness for each control
//    cout << "INPUTS:" << endl;
//    cout << sim_state_variable_inputs.at(0) << endl;
//    cout << "CONTROLS: " << endl;
//    cout << controls_for_population.at(0) << "\t";
//    cout << controls_for_population.at(1) << endl;
    error.clear();
    total_error = 0;
    for (int j = 0; j < target_controls.size(); j++)
    {
        double inputsquared = sim_state_variable_inputs.at(0)*sim_state_variable_inputs.at(0);
        double tar = (inputsquared + 1);
        total_error = (abs(total_control_value - tar));
    }
//cout << "Error" << endl;
//cout << error.size() << endl;
//for (int j = 0; j < error.size(); j++)
//{
//    cout << target_controls.at(j) << "\t";
//    cout << controls_for_population.at(j) << "\t";
//    cout << error.at(j) << endl;
//}
//cout << "\n" << endl;
    //sums the fitness for each control together
//    for (int j = 0; j < error.size(); j++)
//    {
//        total_error += error.at(j);
//    }
////    cout << "Total Error" << endl;
////    cout << total_error << endl;
////    cout << "\n" << endl;
}


//-----------------------------------------------------------------------------------------------------------------------------
//Survival of the fittest
//controls Darwin
void Dummy_EA::Natural_Selection()
{
    //Downselect
    to_kill = pop_size/2;
    //cout << "X1: " << Population.size() << endl;
    for (int j = 0; j < to_kill; j++)
    {
        kill = binary_select();
////        cout << "kill = " << kill << endl;
////        cout << "fitkill = " << Population.at(kill).total_error << endl;
////        int survivor;
////        survivor =0;
////        if(survivor == kill){
////            survivor = 1;
////        }
////        cout << "survivorfit = " << Population.at(survivor).total_error << endl;
        Population.erase(Population.begin() + kill);
     }
    //cout << "X2: " << Population.size() << endl;
    //replicates the surviving weights and then mutates them
    int to_replicate = to_kill;
    for (int j = 0; j < to_replicate; j++)
    {
        Individual A;
        int spot = rand() % Population.size();
        A = Population.at(spot);
        mutation(A.ea_input_to_hidden_layer_weights, A.ea_hidden_to_output_layer_weights);
        Population.push_back(A);
    }
}


//-----------------------------------------------------------------------------------------------------------------------------
//Random Competition
//randomly selects two individuals compares their total errors and decides which one loses
int Dummy_EA::binary_select()
{
    int loser;
    int index_1 = rand() % Population.size();
    int index_2 = rand() % Population.size();
    while(index_1 == index_2){
        index_2 = rand() % Population.size();
    }
    double total_error_1 = Population.at(index_1).total_error;
    double total_error_2 = Population.at(index_2).total_error;
    if (total_error_1 > total_error_2)
    {
        //then individual 2 survives
        loser = index_1;
    }
    else
    {
        loser = index_2;
    }
    return loser;
}


//-----------------------------------------------------------------------------------------------------------------------------
//Mutates the weight of the replication of the survivers
/////////need to make sure it is grabbing the right individual
double Dummy_EA::mutation(vector<double> &ea_input_to_hidden_layer_weights, vector<double> &ea_hidden_to_output_layer_weights)
{
    age = 0;
    for (int j = 0; j < ea_input_to_hidden_layer_weights.size(); j++)
    {
        if (rand() % 10)
        {
            continue;
        }
        double R1 = ((double)rand() / RAND_MAX) * range;
        double R2 = ((double)rand() / RAND_MAX) * range;
        ea_input_to_hidden_layer_weights.at(j) = ea_input_to_hidden_layer_weights.at(j) + (R1-R2);		//creates random weight between 0 and range
    }    for (int j = 0; j < ea_hidden_to_output_layer_weights.size(); j++)
    {
        if (rand() % 10)
        {
            continue;
        }
        double R3 = ((double)rand() / RAND_MAX) * range;
        double R4 = ((double)rand() / RAND_MAX) * range;
        ea_hidden_to_output_layer_weights.at(j) = ea_hidden_to_output_layer_weights.at(j) + R3 - R4;		//creates random weight between 0 and range
    }
//    for (int j = 0; j < ea_input_to_hidden_layer_weights.size(); j++)
//    {
//        cout << ea_input_to_hidden_layer_weights.at(j) << "\t" << endl;
//    }
//    cout << "\n"  << endl;
//    for (int j = 0; j < ea_hidden_to_output_layer_weights.size(); j++)
//    {
//        cout << ea_hidden_to_output_layer_weights.at(j) << "\t" << endl;
//    }
//    cout << "\n" << endl;
    return 1;
}


//-----------------------------------------------------------------------------------------------------------------------------
//Finial Population
//writes the final error and weights for each individual to a text file
void Dummy_EA::write_final_population_to_text(bool display)
{
    ofstream File5;
    File5.open("Final Population.txt");
    if (display)
    for (int j = 0; j < Population.size(); j++)
    {
        File5 << "Individual" << "\t" << j+1 << endl;
        File5 << "Final Total Error" << endl;
        File5 << setprecision(4) << Population.at(j).total_error << endl;
        File5 << "Final Input to Hidden Layer Weights" << endl;
        for (int k = 0; k < Population.at(j).ea_input_to_hidden_layer_weights.size(); k++)
        {
            File5 << setprecision(4) << Population.at(j).ea_input_to_hidden_layer_weights.at(k) << "\t";
        }
        File5 << "\n" << endl;
        File5 << "Final Hidden to Input Layer Weights" << endl;
        for (int k = 0; k < Population.at(j).ea_hidden_to_output_layer_weights.size(); k++)
        {
            File5 << setprecision(4) << Population.at(j).ea_hidden_to_output_layer_weights.at(k) << "\t";
        }
        File5 << "\n" << endl;
    }
    File5.close();
}


//-----------------------------------------------------------------------------------------------------------------------------
//Finial Error and Total Error
//writes the final error and total error to a text file
void Dummy_EA::write_final_error_to_text(bool display, double &total_error)
{
    ofstream File6;
    File6.open("Final Error.txt");
    if(display)
        for (int j = 0; j < Population.size(); j++)
        {
            for ( int k = 0; k < error.size(); k++)
            {
                File6 << setprecision(6) << error.at(k) << "\t";
            }
            File6 << "\n";
            File6 << setprecision(6) << Population.at(j).total_error << "\t";
            File6 << "\n" << endl;
        }
    File6.close();
}