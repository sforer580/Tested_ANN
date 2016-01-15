//
//  Scoreboard.hpp
//  Controller
//
//  Created by Scott Forer on 12/16/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#ifndef Scoreboard_hpp
#define Scoreboard_hpp



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

#include "Individual.hpp"
#include "Dummy EA.hpp"
using namespace std;

class Scoreboard
{
    friend class Neural_Network;
    friend class Layer;
    friend class Node;
    friend class Dummy_simulator;
    friend class Dummy_EA;
    friend class Individual;
    
protected:
    
    
public:

    vector<Individual> Population_clone;
    struct less_than_error;
    void clone_population(Dummy_EA Q);
    void reorder_population();
    double total_output;
    double state;
    void get_best_individual();
    vector<double> best_input_to_hidden_layer_weights;
    vector<double> best_hidden_to_output_layer_weights;
    
    //display functions
    void write_best_info_to_text(bool display);
    void write_best_input_to_hidden_layer_weights_to_text(bool display);
    void write_best_hidden_to_output_layer_weights_to_text(bool display);
    void write_best_indivdual_to_text(Dummy_EA Q);
    
private:
    
    
};

#endif /* Scoreboard_hpp */
