//
//  Individual.cpp
//  Controller
//
//  Created by Scott Forer on 12/4/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#include "Individual.hpp"
//-----------------------------------------------------------------------------------------------------------------------------
//Weight generator
void Individual::create_weights(int sim_number_state_variable_inputs, int sim_hidden_layer_size, int sim_number_controls)
{
    for(int j = 0; j < (sim_number_state_variable_inputs + 1) * sim_hidden_layer_size; j++)
    {
        ea_input_to_hidden_layer_weight = ((double)rand()/RAND_MAX)*1;
        ea_input_to_hidden_layer_weights.push_back(ea_input_to_hidden_layer_weight);
    }
    ////cout << "EA Input to hidden layer weights" << endl;
    ////cout << ea_input_to_hidden_layer_weights.size() << endl;
    //Writes each weight to the console
    ////for (int j = 0; j < ea_input_to_hidden_layer_weights.size(); j++)
    ////{
    ////cout << ea_input_to_hidden_layer_weights.at(j) << "\t";
    ////}
    for(int j = 0; j < ((sim_hidden_layer_size+1)*sim_number_controls); j++)
    {
        ea_hidden_to_output_layer_weight = ((double)rand()/RAND_MAX)*1;
        ea_hidden_to_output_layer_weights.push_back(ea_hidden_to_output_layer_weight);
    }
    ////cout << "\n" << endl;
    ////cout << "EA Hidden to ouput layer weights" << endl;
    ////cout << ea_hidden_to_output_layer_weights.size() << endl;
    //Writes each weight to the console
    ////for (int i = 0; i < ea_hidden_to_output_layer_weights.size(); i++)
    ////{
    ////cout << ea_hidden_to_output_layer_weights.at(i) << "\t";
    ////}
    ////cout << "\n" << endl;
}


//-----------------------------------------------------------------------------------------------------------------------------
//Communication from Simulator
void Individual::get_state_variables(vector<double> &sim__state_variable_inputs)
{
    state_for_individual.clear();
    for (int j = 0; j < sim__state_variable_inputs.size(); j++)
    {
        state_for_individual.push_back(sim__state_variable_inputs.at(j));
    }
}


void Individual::sum_controls()
{
    total_control_value = 0;
    for (int j = 0; j < controls_for_population.size(); j++)
    {
//        cout << controls_for_population.size() << endl;
//        cout << controls_for_population.at(j) << "\t" << endl;
        total_control_value += controls_for_population.at(j);
//        cout << total_control_value << endl;
    }
}



void Individual::get_best_weights(vector<double> &best_input_to_hidden_layer_weights, vector<double> &best_hidden_to_output_layer_weights)
{
    ea_input_to_hidden_layer_weights.clear();
    ea_hidden_to_output_layer_weights.clear();
    for(int j = 0; j < best_input_to_hidden_layer_weights.size(); j++)
    {
    ea_input_to_hidden_layer_weights.push_back(best_input_to_hidden_layer_weights.at(j));
    }
    for(int j = 0; j < best_hidden_to_output_layer_weights.size(); j++)
    {
        ea_hidden_to_output_layer_weights.push_back(best_hidden_to_output_layer_weights.at(j));
    }
//    //Writes each weight to the console
//    for (int j = 0; j < ea_input_to_hidden_layer_weights.size(); j++)
//    {
//        cout << ea_input_to_hidden_layer_weights.at(j) << "\t";
//    }
//    for (int j = 0; j < ea_hidden_to_output_layer_weights.size(); j++)
//    {
//        cout << ea_hidden_to_output_layer_weights.at(j) << "\t";
//    }
}


//void Individual::write_state_and_sum_control_to_text(bool display)
//{
//    cout << "cp1" << endl;
//    cout << state_for_individual.at(0) << endl;
//    cout << total_control_value << endl;
//    ofstream File11;
//    if(display)
//    {
//     File11 << setprecision(6) << state_for_individual.at(0) << "\t";
//        File11 << setprecision(6) << total_control_value;
//        File11 << "\n" << endl;
//    }
//}
