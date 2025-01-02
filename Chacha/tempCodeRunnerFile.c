for(uint32_t i = 0; i < 1; i++){
            for(uint32_t j = 0; j < 16; j++){
                printf("%08x    ",state_matrix[i][j]);

                if(j % 4 == 3){
                    printf("\n");
                }
            }
        }