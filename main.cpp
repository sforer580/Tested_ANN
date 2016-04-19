//
//  main.cpp
//  ANN
//
//  Created by Scott Forer on 1/15/16.
//  Copyright © 2016 Scott Forer. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <iomanip>

#include "Neural Network.hpp"
#include "Dummy Simulator.hpp"
#include "Dummy EA.hpp"
#include "Individual.hpp"
#include "Scoreboard.hpp"

using namespace std;

int main()
{
    srand(time(NULL));
    Neural_Network NN;
    Dummy_simulator DS;
    Dummy_EA EA;
    Individual IND;
    Scoreboard SB;
    DS.create_state_variable_limits();  //FOR TESTING ONLY
    //creates the tagret controls for comparison
    EA.create_target_controls();        //FOR TESTING ONLY
    //Builds the populaiton of weights
    EA.build_population(DS.sim_number_state_variable_inputs, DS.sim_hidden_layer_size, DS.sim_number_controls);     //FOR TESTING ONLY
    NN.initialize(0,0);        //Initalizes the Neural Network sets layer sizes to 0
    NN.take_input_limits(DS.sim_state_variable_lower_limits, DS.sim_state_variable_upper_limits);
    NN.take_output_limits(DS.sim_control_lower_limits, DS.sim_control_upper_limits);
    NN.take_num_controls(DS.sim_number_controls);
    NN.take_num_hidden_units(DS.sim_hidden_layer_size);
    ofstream File7; //FOR TESTING ONLY
    File7.open("Error_For_Each_Population.txt");    //FOR TESTING ONLY
    //excutes the Neural Network and EA for enitire population
    for(int i = 0; i < EA.generations; i++)
    {
        DS.create_state_variables();      //for dynamic case
        cout << "generation" << "\t" << i+1 << endl;
        for (int h  = 0; h < EA.pop_size; h++)
        {
            //Begin Neural Network Calculations
            IND = EA.Population.at(h);
            NN.take_weights(IND.ea_input_to_hidden_layer_weights, IND.ea_hidden_to_output_layer_weights);
            IND.get_state_variables(DS.sim_state_variable_inputs);
            NN.activation_function(DS.sim_state_variable_inputs);
            IND.controls_for_population = NN.communication_to_simulator();//FOR TESTING ONLY
            NN.Neural_Network_Reset();    //allows the Neural network to use state variables
            //End Neural Network Calculations
            
            //Begin EA Calculations
            IND.sum_controls();     //FOR TESTING ONLY
            EA.get_error(IND.total_control_value, IND.total_error, DS.sim_state_variable_inputs);   //FOR TESTING ONLY
            EA.Population.at(h) = IND;  //FOR TESTING ONLY
            File7 << setprecision(6) << IND.total_error << "\t";    //FOR TESTING ONLY
        }
        //no mutation on last generation
        if ( i < EA.generations - 1)
        {
            EA.Natural_Selection();     //FOR TESTING ONLY
            //End EA Calculations
        }
    }
    File7.close();      //FOR TESTING ONLY
    SB.write_best_indivdual_to_text(EA);    //FOR TESTING ONLY
    EA.write_final_population_to_text(true);    //FOR TESTING ONLY
    EA.write_final_error_to_text(true, IND.total_error);    //FOR TESTING ONLY
    //////////////////////////////////////////////////////////
    //After Training
    //FOR TESTING ONLY
    IND.get_best_weights(SB.best_input_to_hidden_layer_weights, SB.best_hidden_to_output_layer_weights);
    //cout << "After training" << endl;
    ofstream File11;
    File11.open("state_variable_and_total_output.txt");
    for (int i = 0; i < 1000; i++)
    {
        DS.create_state_variables();
        IND.get_state_variables(DS.sim_state_variable_inputs);
        NN.activation_function(DS.sim_state_variable_inputs);
        IND.controls_for_population = NN.communication_to_simulator();
        NN.Neural_Network_Reset();
        IND.sum_controls();
        File11 << setprecision(6) << IND.state_for_individual.at(0) << "\t";
        File11 << setprecision(6) << IND.total_control_value;
        File11 << "\n" << endl;
    }
    File11.close();
    //////////////////////////////////////////////////////////
    return 0;
}
