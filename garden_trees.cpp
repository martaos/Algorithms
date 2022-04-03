/*      Algorytm dotyczący problemu przesadzania drzew      */
/*      Działka podzielona jest na kwadraty                 */
/*      Na każdym kwadracie ma być taka sama ilość drzew    */
/*      Możemy albo przesadzać między kwadratami, albo dosadzać nowe        */
/*      Jak zrobić to w najmniejszej liczbie ruchów?        */



#include <algorithm>

int solution(vector<int> &A) {
sort(A.begin(), A.end(), greater<int>());
int min = 0;
int k;
int N = distance(A.begin(), A.end()) - 1; // max numer elementu
  while(!equal(A.begin()+1, A.end(), A.begin())){
    for(k = 0; k <= N/2; k++){
      while(A[k] != A[N-k]){
        if(A[k] - A[N-k] >= 2){
          int R = (A[k] - A[N-k])/2;
          A[k] -= R;
          A[N-k] += R;
          min += R;
        }
        else{
          A[N-k]++; 
          min++;
        } 
      }
    }
    sort(A.begin(), A.end(), greater<int>());
  }
return min;
}
