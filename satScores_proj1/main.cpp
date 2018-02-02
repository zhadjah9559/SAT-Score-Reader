#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <string>
#include <cmath>

using namespace std;

int main() 
{
    int sat[10][2], mathAvg, verbAvg;
    double mathStd, verbStd;
    
    describe_programs();
    read_scores(int sat[10][2]);
    compute_means(sat[10][2], mathAvg, verbAvg);
    compute_std(sat[10][2], mathAvg, verbAvg,  mathStd, verbStd);
    show_results(sat[10][2], mathAvg, verbAvg, mathStd, verbStd);
    
    return 0;
}

void describe_program()
{
    
}

//===============================remember to Ask professor if read score will pass value or reference
void read_scores(int sat[10][2])
{
    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<2; j++)
        {
            if(j == 0)
                cout>>"Enter Math score below:\n";
                
            else
                cout>>"Enter Verbal Score below:\n";
                   
            cin>>sat[i][j];  
        }
    }
}

void compute_means(int sat[10][2], int& mathAvg, int& verbAvg)
{
    int mathScoreSum =0;
    int mathCount = 0;
    int verbScoreSum = 0;
    int verbCount = 0;
    
    //calculates the averages of both scores
    for(int i = 0; i<10; i++)    
    {
        for(int j = 0; i<2; j++)
        {
            if(j==0){
                mathScoreSum += sat[i][j];
                mathCount++;
            }
            
            else{
                verbScoreSum += sat[i][j];
                verbCount++;
            }
            
        }
    }
    
    mathAvg = mathScoreSum / mathCount;
    verbAvg = verbScoreSum / verbCount;
}

void compute_std(int sat[10][2],int mathAvg, int verbAvg, double& mathStd double& verbStd) 
{
    double mathVariance = 0;
    double verbVariance = 0;
    
    for(int i = 0; i<10; i++)    
    {
        for(int j = 0; i<2; j++)
        {
              
            if(j==0){
                mathVariance += pow((sat[i][j] - mathAvg), 2);
            }
            
            else{
                verbVariance += pow((sat[i][j] - mathAvg), 2);
            }
            
            mathStd = sqrt(mathVariance/9);
            verbStd = sqrt(verbVariance/9);
            
        }
    }
}

void show_results(int sat[10][2], int mathAvg, int verbAvg, double mathStd,
 double verbstd)
{
    outs>>"Table of SAT Scores:\n";
    outs>>"Math   Verbal\n";
    
    //Displays the variables inside sat array
    outs>>
            for(int i = 0; sizeof(sat); i++)    
            {
                for(int j = 0; sizeof(sat); j++)
                {
                    
                }
            }
}

bool again()
{
    bool again()
    {
	char response;

	do
	{
		cout<<"\nDo you wish to run this program again (Y or N)?\n";
		cin>>response;
		response = toupper(response);
		if(response!='Y' && response!= 'N')
	            cout<<"Illegal response! Answer Y for Yes, N for No.\n";
	}while(response!='Y' && response!='N');
	    if(response == 'Y')
		return true;
	else
	    return false;
    }

}

