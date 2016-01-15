//
//  Scoreboard.cpp
//  Controller
//
//  Created by Scott Forer on 12/16/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#include "Scoreboard.hpp"

void Scoreboard::clone_population(Dummy_EA Q)
{
    this->Population_clone = Q.Population;
    
}


//-----------------------------------------------------------------------------------------------------------------------------
//
struct Scoreboard::less_than_error
{
    inline bool operator() (Individual& A1, Individual& A2)
    {
        return (A1.total_error > A2.total_error);
    }
};


//-----------------------------------------------------------------------------------------------------------------------------
//reorders vector of solutions
void Scoreboard::reorder_population()
{
    sort(Population_clone.begin(), Population_clone.end(), less_than_error());
}


//-----------------------------------------------------------------------------------------------------------------------------
//Get best individual information
void Scoreboard::get_best_individual()
{
    total_output = 0;
    state = 0;
    best_input_to_hidden_layer_weights.clear();
    best_hidden_to_output_layer_weights.clear();
    for (int j = 0; j < Population_clone.at(0).controls_for_population.size(); j++)
    {
        total_output += Population_clone.at(0).controls_for_population.at(j);
    }
    for (int j = 0; j < Population_clone.at(0).state_for_individual.size(); j++)
    {
        state = Population_clone.at(0).state_for_individual.at(j);
    }
    for (int j = 0; j < Population_clone.at(0).ea_input_to_hidden_layer_weights.size(); j++)
    {
        best_input_to_hidden_layer_weights.push_back(Population_clone.at(0).ea_input_to_hidden_layer_weights.at(j));
    }
    for (int j = 0; j < Population_clone.at(0).ea_hidden_to_output_layer_weights.size(); j++)
    {
        best_hidden_to_output_layer_weights.push_back(Population_clone.at(0).ea_hidden_to_output_layer_weights.at(j));
    }
}

////-----------------------------------------------------------------------------------------------------------------------------
////Writes best individual state variables and total output to text
//void Scoreboard::write_best_info_to_text(bool display)
//{
//    ofstream File8;
//    File8.open("total_output_and_state.txt");
//    if(display)
//    {
//        File8 << setprecision(6) << state << "\t";
//        File8 << setprecision(6) << total_output << endl;;
//
//    }
//    File8.close();
//}

//-----------------------------------------------------------------------------------------------------------------------------
//Write best individual information
void Scoreboard::write_best_input_to_hidden_layer_weights_to_text(bool display)
{
    ofstream File9;
    File9.open("best input to hidden layer weights.txt");
    if(display)
    {
        for (int j = 0; j < best_input_to_hidden_layer_weights.size(); j++)
        {
           File9 << setprecision(6) << best_input_to_hidden_layer_weights.at(j) << "\t";
        }
    }
    File9.close();
}

//-----------------------------------------------------------------------------------------------------------------------------
//Write best individual information
void Scoreboard::write_best_hidden_to_output_layer_weights_to_text(bool display)
{
    ofstream File10;
    File10.open("best hidden to output layer weights.txt");
    if(display)
    {
        for (int j = 0; j < best_hidden_to_output_layer_weights.size(); j++)
        {
            File10 << setprecision(6) << best_hidden_to_output_layer_weights.at(j) << "\t";
        }
    }
    File10.close();
}

void Scoreboard::write_best_indivdual_to_text(Dummy_EA Q)
{
    clone_population(Q);
    less_than_error;
    reorder_population();
    get_best_individual();
    //write_best_info_to_text(true);
    write_best_input_to_hidden_layer_weights_to_text(true);
    write_best_hidden_to_output_layer_weights_to_text(true);
}