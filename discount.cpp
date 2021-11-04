#include <iostream>

int main(){
    double N, A, B, X, Y;

    std::cin >> N >> A >> B >> X >> Y;

    if (N > B){
        N*=(1.0 - Y/100.0);
    }
    else if(N > A){
        N*=(1.0 - X/100.0);
    }

    std::cout << N;


    return 0;
}