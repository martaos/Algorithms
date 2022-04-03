/*          Algorytm rozwiązujący problem rozdzielania samochodów między dystrybutorami paliwa      */
/*          Każdy dystrybutor ma określoną ilość paliwa, czas tankowania przyjmujemy na ilość paliwa ile auto pobierze      */
/*          Auto ma wybrać dystrybutor o najkrótszym czasie oczekiwania  i z dostępną ilością wymaganego paliwa             */
/*          Dodatkowo ma wybierać dystrybutor możliwie najbliżej "lewej" strony                                             */
/*          Algorytm ma wyliczyć najbardziej optymalny podział aut w celu zminimalizowania oczekiwania                      */
/*          Zwraca czas najdłużej oczekująego auta                                                                          */



int solution(vector<int> &A, int X, int Y, int Z){
    int time[3] = {0, 0, 0};                //ile by moglo czekac auto
    int max_time[3] = {0, 0, 0};            //ile czeka ostatnie auto ktore chce podjechac
    int dysp = 0;                           //mowi do ktorego dystrybutora najlepiej podjechac
    int dystrybutory[3] = {X, Y, Z};
    unsigned long i = 0;
    int max = 0;
    while(i < A.size()){
        if(A[i] > X && A[i] > Y && A[i] > Z) return -1;     //jesli nigdzie nie ma paliwa to -1
        else{
            for(int j = 0; j < 3; j++){
                if(time[j] == 0 && (dystrybutory[j] >= A[i])){      //jesli dystrybutor ma tyle paliwa 
                    dysp = j;                                     // i jest wolny - wybierz ten
                    break;                                  
                }
                else{
                   dysp = 0;                                       //jak nie - pojedz do pierwszego 
                }
            }
            for(int j = 0; j < 3; j++){                         //sprwadz czy mozesz
                if(!(dystrybutory[dysp] >= A[i])){
                    dysp++;
                }
            }
            for(int j = 0; j < 2; j++){
                if((time[j] > time[j+1]) && (dystrybutory[j+1] >= A[i])){
                    dysp = j+1;                                    //jesli czeka krocej niz w blizszym
                                                                    //i jest tyle paliwa - jedz
                }
                else{
                    continue;
                }
            }
            dystrybutory[dysp] -= A[i];
            max_time[dysp] = time[dysp];
            time[dysp] += A[i];
        }
        i++;
    }
    for(int i = 0; i <3; i++){
        if(max_time[i] > max) max = max_time[i];
    }
    return max;
}