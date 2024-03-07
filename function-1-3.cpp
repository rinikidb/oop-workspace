#include <iostream>
using namespace std;
void count_digits(int array[4][4]){
    int sum0 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    int sum5 = 0;
    int sum6 = 0;
    int sum7 = 0;
    int sum8 = 0;
    int sum9 = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int x = array[i][j];
            switch(x){
                case 0:
                    sum0 += 1;
                    break;
                case 1:
                    sum1 += 1;
                    break;
                case 2:
                    sum2 += 1;
                    break;
                case 3:
                    sum3 += 1;
                    break;
                case 4:
                    sum4 += 1;
                    break;
                case 5:
                    sum5 += 1;
                    break;
                case 6:
                    sum6 += 1;
                    break;
                case 7:
                    sum7 += 1;
                    break;
                case 8:
                    sum8 += 1;
                    break;
                case 9:
                    sum9 += 1;
                    break;
                default:
                    break;
            }
        }
    }
    cout << "0:" << sum0 << ";" << "1:" << sum1 << ";" << "2:" << sum2 << ";" << "3:" << sum3 << ";" << "4:" << sum4 << ";" << "5:" << sum5 << ";" << "6:" << sum6 << ";" << "7:" << sum7 << ";" << "8:" << sum8 << ";" << "9:" << sum9 << ";" << endl;
}