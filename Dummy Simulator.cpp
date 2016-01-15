//
//  Dummy Simulator.cpp
//  Controller
//
//  Created by Scott Forer on 11/19/15.
//  Copyright © 2015 Scott Forer. All rights reserved.
//

#include "Dummy Simulator.hpp"

//-----------------------------------------------------------------------------------------------------------------------------
//Dummy state varibale generator
//Randomly creates the state variables
void Dummy_simulator::create_state_variables()
{
    //given the number of state variable the for loop randomly creates numbers between 0 and 10 and push them back into a vector
    sim_state_variable_inputs.clear();
    for (int i = 0; i < sim_number_state_variable_inputs; i++)
    {
        double R1 = ((double)rand());
        double R2 = RAND_MAX;
//        cout << R1 << endl;
//        cout << R2 << endl;
        sim_state_variable = (R1/R2) * 3;
        sim_state_variable_inputs.push_back(sim_state_variable);
    }
//    cout << "S\t";
//    cout << sim_state_variable_inputs.at(0) << endl;
//    cout << "SSV: " << sim_state_variable_inputs.at(0);
//    sim_state_variable_inputs.push_back(0.57854839);
//    
//    sim_state_variable_inputs.push_back(3.27854839);
//    
//    sim_state_variable_inputs.push_back(8.37854839);
//    
//    sim_state_variable_inputs.push_back(2.97854839);
//    
//    sim_state_variable_inputs.push_back(1.67854839);
    ////cout << "Simulator Unnormalized State Variable Inputs" << endl;
    ////cout << sim_state_variable_inputs.size() << endl;
    //Writes each unnormalized state variable to the console
    ////for (int i = 0; i < sim_number_state_variable_inputs; i++)
    ////{
        ////cout << sim_state_variable_inputs.at(i) << "\t";
    ////}
   ////cout << "\n" << endl;
}


//-----------------------------------------------------------------------------------------------------------------------------
//Dummy state variable limit generator
//Creates the upper and lower limits for each state variable
void Dummy_simulator::create_state_variable_limits()
{
    sim_state_variable_upper_limits.push_back(3);
//    sim_state_variable_upper_limits.push_back(3);
//    sim_state_variable_upper_limits.push_back(3);
//    sim_state_variable_upper_limits.push_back(3);
//    sim_state_variable_upper_limits.push_back(3);
    ////cout << "Simulator State Variable Upper Limits" << endl;
    ////cout << sim_state_variable_upper_limits.size() << endl;
    //Writes each upper limit to the console
    ////for(int i = 0; i < sim_number_state_variable_inputs; i++)
    ////{
        ////cout << sim_state_variable_upper_limits.at(i) << "\t";
    ////}
    ////cout << "\n" << endl;
    sim_state_variable_lower_limits.push_back(0);
//    sim_state_variable_lower_limits.push_back(0);
//    sim_state_variable_lower_limits.push_back(0);
//    sim_state_variable_lower_limits.push_back(0);
//    sim_state_variable_lower_limits.push_back(0);
    ////cout << "Simulator State Variable Lower Limits" << endl;
    ////cout << sim_state_variable_lower_limits.size() << endl;
    //Writes each lower limit to the console
    ////for(int i = 0; i < sim_number_state_variable_inputs; i++)
    ////{
        ////cout << sim_state_variable_lower_limits.at(i) << "\t";
    ////}
    ////cout << "\n" << endl;
    
    sim_control_upper_limits.push_back(15);
    sim_control_upper_limits.push_back(15);
    ////cout << "Simulator Control Lower Limits" << endl;
    ////cout << sim_control_upper_limits.size() << endl;
    //Writes each lower limit to the console
    ////for(int i = 0; i < sim_control_upper_limits.size(); i++)
    ////{
        ////cout << sim_control_upper_limits.at(i) << "\t";
    ////}
    ////cout << "\n" << endl;
    sim_control_lower_limits.push_back(0);
    sim_control_lower_limits.push_back(0);
    ////cout << "Simulator Control Lower Limits" << endl;
    ////cout << sim_control_lower_limits.size() << endl;
    //Writes each lower limit to the console
    ////for(int i = 0; i <sim_control_lower_limits.size(); i++)
    ////{
        ////cout << sim_control_lower_limits.at(i) << "\t";
    ////}
    ////cout << "\n" << endl;
}

