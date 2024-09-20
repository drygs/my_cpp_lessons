void readMatriz(int array[][3], int size){

    int lower = array[0][0];
    int line = 0;

    for(int i = 0; i < size; i++){
        for(int n = 0; n < size; n++){
            if(array[i][n] < lower){

                lower = array[i][n];
                //line = i;
            } 
        }
    }