/*==============================================================================
 Zachary Hadjah                    February 9th 2018
 Junior Year                       Data Structures/ Algorithm Analysis
  
 This program reads the scores of 10 students SAT scores. It reads the math
 and verbal sections of the SAT test, putting the math scores in the right column,
 and the verbal scores in the left column. It will also compute the the average 
 * of all the math averages and verbal averages.
 =============================================================================*/
#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <cmath>
#include <cctype>

using namespace std;

/**
 * 
 * @return 0
 */
int main() 
{
    int sat[10][2], mathAvg, verbAvg;
    double mathStd, verbStd;
    
    void describe_program();
    void read_scores(int sat[10][2]);
    void compute_means(int sat[10][2], int& mathAvg, int& verbAvg);
    void compute_std(int sat[10][2],int mathAvg, int verbAvg, double& mathStd, double& verbStd) ;
    void show_results(int sat[10][2], int mathAvg, int verbAvg, double mathStd,  double verbstd);
    bool again();

    describe_program();
    read_scores(sat);
    compute_means(sat, mathAvg, verbAvg);
    compute_std(sat, mathAvg, verbAvg,  mathStd, verbStd);
    //show_results(sat, mathAvg, verbAvg, mathStd, verbStd);
    //again();
    return 0;
}

/*
 * 
 */
void describe_program()
{
    cout<<"This program reads SAT scores from 10 students (Math and verbal scores)"
        <<" and allocates the scores as elements inside a two dimensional array."
        <<endl<<"The program will then calculate the mean Math SAT score, the mean "
        <<"Verbal SAT score, and the standard deviation for both subjects."<<endl<<
        "The results will be sent to the user in a tabular format and will then "
        <<"be sent to text file."<<endl; 
}

/**
 * 
 * @param sat
 */
void read_scores(int sat[10][2])
{
    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<2; j++)
        {
            if(j == 0){
                cout<<"Enter Math score below:"<<endl;
            }
                
            else{
                cout<<"Enter Verbal Score below:"<<endl;
            }    
            cin>>sat[i][j];  
        }
    }
}

/**
 * 
 * @param sat
 * @param mathAvg
 * @param verbAvg
 */
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

/**
 * 
 * @param sat
 * @param mathAvg
 * @param verbAvg
 * @param mathStd
 * @param verbStd
 */
void compute_std(int sat[10][2],int mathAvg, int verbAvg, double& mathStd, double& verbStd) 
{
    double mathVariance = 0;
    double verbVariance = 0;
    
    for(int i = 0; i<10; i++)    
    {
        for(int j = 0; i<2; j++)
        {
              
            if(j==0){
                //mathVariance += pow((sat[i][j] - mathAvg), 2);
            }
            
            else{
                //verbVariance += pow((sat[i][j] - mathAvg), 2);
            }
            
            mathStd = sqrt(mathVariance/9);
            verbStd = sqrt(verbVariance/9);
            
            //testing to see if it works
            cout<<mathStd<<endl<<verbStd;
        }
    }
}

/**
 * 
 * @param sat
 * @param mathAvg
 * @param verbAvg
 * @param mathStd
 * @param verbstd
 */
void show_results(int sat[10][2], int mathAvg, int verbAvg, double mathStd, double verbstd)
{
    ofstream file;
    file.open("scores.txt");
    file.close();
    
    /*outs>>"Table of SAT Scores:\n";
    outs>>"Math   Verbal\n";
    
    //Displays the variables inside sat array
    outs>>
            for(int i = 0; sizeof(sat); i++)    
            {
                for(int j = 0; sizeof(sat); j++)
                {
                    
                }
            }*/
}

/**
 * 
 * @return Bool variable
 */
bool again()
{
    char response;
    
    cout<<endl<<"Do you wish to run this program again (Y or N)?"<<endl;
    cin>>response;
    response = toupper(response);

    while((response!='Y') || (response!= 'N'))
        cout<<"Illegal response! Answer Y for Yes, N for No.\n";
       
    if(response == 'Y')
        return true;
    else
        return false;    
}

