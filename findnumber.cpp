#include<iostream>
#include<cmath>
using namespace std;

// trial and error method
// function r**3 - 43.19*r = 13.45

float p_func(float r);
float r_return(float func_val, float compute_val, float rr); 
void show_process(float func_val, float compute_val, float rr);

int main(){
    float r = 5.0;
    float err = 0.1;
    float final_val = 13.45;
	int round = 1;

    while(1!=0)
    {
        float temp = p_func(r);
        show_process(final_val, temp, r);
        if (abs(temp - final_val) < err){
            break;
        }
        else
        {
            r = r_return(temp, final_val,r);
        }
		round += 1;
    }
    cout << "r is approach to " << r << endl;
	cout << p_func(r) << endl;
	cout << "round : "<< round << endl;
    return 0;
}

float p_func(float r){
	// the polynomial function
    return pow(r,3)-43.19*r;
}
float r_return(float func_val, float compute_val, float rr){
	// the algorithm of r
    if (func_val < compute_val) // r is too small
    {
        rr = 1.5*rr;
    }
    else    // r is too big
    {
        rr = 0.5*rr;
    }
    return rr;
}
void show_process(float func_val, float compute_val, float rr){
    cout << "r: " << rr << "\t compute: " << compute_val<<
    "\t final_val: " << func_val << endl;
}