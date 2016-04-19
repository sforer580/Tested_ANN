//
//  Dummy EA.hpp
//  Controller
//
//  Created by Scott Forer on 11/19/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#ifndef Dummy_EA_hpp
#define Dummy_EA_hpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <iomanip>


#include "Individual.hpp"

using namespace std;

class Dummy_EA
{
    friend class Neural_Network;
    friend class Layer;
    friend class Node;
    friend class Dummy_simulator;
    friend class Individual;
    friend class Scoreboard;
    
protected:
    
    
public:
    //Population Framework
    int pop_size = 100;
    vector<Individual> Population;
    
    //Target Controls
    int control_one = 3;
    int control_two = 5;
    vector<int> target_controls;
    void create_target_controls();
    
    //Population activation
    void build_population(int sim_number_state_variable_inputs, int sim_hidden_layer_size, int sim_number_controls);
    
    //Fitness
    void get_error(double &total_control_value, double &total_error, vector<double> &sim_state_variable_inputs);
    vector<double> error;
    
    //Darwin
    void Natural_Selection();
    int to_kill;
    int kill;
    int binary_select();
    double mutation(vector<double> &ea_input_to_hidden_layer_weights, vector<double> &ea_hidden_to_output_layer_weights);
    int age;
    double range = .1;
    int generations = 10000;
    
    //Displays
    void write_final_population_to_text(bool display);
    void write_final_error_to_text(bool display, double &total_error);
    
    
    
private:
    
    
};

#endif /* Dummy_EA_hpp */
