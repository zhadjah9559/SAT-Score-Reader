/*==============================================================================
 Zachary Hadjah                    February 9th 2018
 Junior Year                       Data Structures/ Algorithm Analysis
  
 This program reads the scores of 10 students SAT scores. 
 * read_scores() will ask the user to input 10 Math and Verbal scores
 * compute_means() will compute the averages of all ten tests for both subjects
 * compute_std() will compute the standard deviation of all ten tests for both 
   subjects
 * show_results() will display the results to the user in a tabular format and 
   then send the scores to the scores.txt file. 
 * again() will ask the user if they want to redo the program
 =============================================================================*/
#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <cmath>
#include <cctype>

using namespace std;

void describe_program();
void read_scores(int sat[10][2]);
void compute_means(int sat[10][2], int& mathAvg, int& verbAvg);
void compute_std(int sat[10][2],int mathAvg, int verbAvg, double& mathStd, double& verbStd) ;
void show_results(int sat[10][2], int mathAvg, int verbAvg, double mathStd,  double verbstd);
bool again();

/**
 * 
 * @return 0
 */
int main() 
{
    int sat[10][2], mathAvg, verbAvg;
    double mathStd, verbStd;    

    describe_program();
    
    do
    {
        read_scores(sat);
        compute_means(sat, mathAvg, verbAvg);
        compute_std(sat, mathAvg, verbAvg,  mathStd, verbStd);
        show_results(sat, mathAvg, verbAvg, mathStd, verbStd);
    }while(again());
    
    return 0;
}

/**
 * 
 */
void describe_program()
{
    cout<<"This program reads SAT scores from 10 students (Math and verbal scores)"
        " and allocates the scores as elements inside a two dimensional array. \n"
        "The program will then calculate the mean Math SAT score, the mean "
        "Verbal SAT score, and the standard deviation for both subjects. \n"
        "The results will be sent to the user in a tabular format and will then "
        "be sent to text file. \n"; 
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
    
    for(int i = 0; i<10; i++)    
    {
        for(int j = 0; j<2; j++)
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
        for(int j = 0; j<2; j++)
        {
            if(j==0){
                mathVariance += ::pow((sat[i][j] - mathAvg), 2);
            }
            
            else{
                verbVariance += ::pow((sat[i][j] - mathAvg), 2);
            }
            
            mathStd = sqrt(mathVariance/9);
            verbStd = sqrt(verbVariance/9);
        }
    }
}

/**
 * 
 * @param sat
 * @param mathAvg
 * @param verbAvg
 * @param mathStd
 * @param verbStd
 */
void show_results(int sat[10][2], int mathAvg, int verbAvg, double mathStd, double verbStd)
{ 
    cout<<fixed<<showpoint<<setprecision(1);
    cout<<setw(13)<<"MATH"<<setw(13)<<"VERBAL"<<endl;
    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<2;j++)
        {
            if(j==0){
                cout<<setw(13)<<sat[i][j];
            }else{
                cout<<setw(13)<<sat[i][j]<<endl;
            }
        }
    }
    cout<<"MEAN"<<setw(9)<<mathAvg<<setw(13)<<verbAvg<<endl;
    cout<<"STD"<<setw(10)<<mathStd<<setw(13)<<verbStd;
       
    ofstream outs;
    outs.open("scores.txt",ios::app);
    
    outs<<fixed<<showpoint<<setprecision(1);
    outs<<setw(13)<<"MATH"<<setw(13)<<"VERBAL"<<endl;
    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<2;j++)
        {
            if(j==0){
                outs<<setw(13)<<sat[i][j];
            }else{
                outs<<setw(13)<<sat[i][j]<<endl;
            }
        }
    }
    outs<<"MEAN"<<setw(9)<<mathAvg<<setw(13)<<verbAvg<<endl;
    outs<<"STD"<<setw(10)<<mathStd<<setw(13)<<verbStd<<endl;
    outs.close(); 
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
        
    while((response!= 'N') && (response!= 'Y') && (response!= 'y') &&
          (response!= 'n')){
        cout<<"Please enter a valid response";
        cin>>response;
    }
    
    response = toupper(response);
    
    return response == 'Y';
}