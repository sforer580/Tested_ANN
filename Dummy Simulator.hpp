//
//  Dummy Simulator.hpp
//  Controller
//
//  Created by Scott Forer on 11/19/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#ifndef Dummy_Simulator_hpp
#define Dummy_Simulator_hpp

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

class Dummy_simulator
{
    friend class Neural_Network;
    friend class Layer;
    friend class Node;
    friend class Dummy_EA;
    friend class Individual;
    friend class Scoreboard;
    
protected:
    
    
public:
    int sim_number_state_variable_inputs = 1;
    int sim_hidden_layer_size = 3;
    int sim_number_controls = 2;
    void create_state_variables();
    double sim_state_variable;
    vector<double> sim_state_variable_inputs;
    void create_state_variable_limits();
    vector<double> sim_state_variable_upper_limits;
    vector<double> sim_state_variable_lower_limits;
    vector<double> sim_control_upper_limits;
    vector<double> sim_control_lower_limits;
    vector<double> controls_for_simulator;
    
    
private:
    
    
};

#endif /* Dummy_Simulator_hpp */
