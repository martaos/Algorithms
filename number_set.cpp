/*          Algorytm zwraca N wartość z ciągu liczb:                    */
/*          {1,2,3,5,8,13,12,7.....},                                   */
/*          dla którego każdy kolejny wyraz jest sumą cyfr dwóch poprzednich wyrazów      */


int suma(int n){
    int suma = 0;
    while(n){
        suma += n%10;
        n /= 10;
    }
    return suma;
}

int solution(int N){ 
    int arr[24];
    if(N == 0) return 0;
    if(N == 1 || N == 2) return 1;
    int a1 = 1, a2 = 1;
    for(int i = 0; i <= 23; i++){
        arr[i] = suma(a1) + suma(a2);
        a1 = a2;
        a2 = arr[i];
    }
    return (N -3 < 24) ? arr[N-3] : arr[(N-3)%23-1];
}
