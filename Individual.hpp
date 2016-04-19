//
//  Individual.hpp
//  Controller
//
//  Created by Scott Forer on 12/4/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#ifndef Individual_hpp
#define Individual_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

class Individual
{
    friend class Neural_Network;
    friend class Layer;
    friend class Node;
    friend class Dummy_simulator;
    friend class Dummy_EA;
    friend class Scoreboard;
    
protected:
    
    
public:
    //Weight generation
    double ea_input_to_hidden_layer_weight;
    vector<double> ea_input_to_hidden_layer_weights;
    double ea_hidden_to_output_layer_weight;
    vector<double> ea_hidden_to_output_layer_weights;
    void create_weights(int sim_number_state_variable_inputs, int sim_hidden_layer_size, int sim_number_controls);
    
    //Communication from Simulator
    vector<double> state_for_individual;
    void get_state_variables(vector<double> &sim__state_variable_inputs);
    
    //Communication from Neural Network
    vector<double> controls_for_population;

    
    //Communication to and from EA
    double total_error;
    
    void get_best_weights(vector<double> &best_input_to_hidden_layer_weights, vector<double> &best_hidden_to_output_layer_weights);
    double total_control_value;
    void sum_controls();
    void write_state_and_sum_control_to_text(bool display);
    
private:
    
    
};

#endif /* Individual_hpp */
