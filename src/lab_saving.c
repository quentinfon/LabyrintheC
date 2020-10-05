#include "lab_saving.h"

int is_cfg_format(struct dirent *dir){

    int size = dir->d_namlen;

    if (dir->d_namlen > 4){

        if (dir->d_name[size-4] == '.' && dir->d_name[size-3] == 'c' && dir->d_name[size-2] == 'f' && dir->d_name[size-1] == 'g'){
            return 1;
        }else{
            return 0;
        }

    }else{
        return 0;
    }

}

int is_in_file_list(char * file_name){
    DIR *d;
    struct dirent *dir;
    d = opendir("../save");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (is_cfg_format(dir)){
                /*removing the file extension*/
                dir->d_name[dir->d_namlen-4] = '\0';
                if (strcmp(dir->d_name, file_name) == 0){
                    return 1;
                }
            }
        }
        closedir(d);
    }
    return 0;
}

void display_save_list(){
    DIR *d;
    struct dirent *dir;
    d = opendir("../save");
    /*number of lab saved*/
    int count = 0;

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (is_cfg_format(dir)){
                /*removing the file extension*/
                dir->d_name[dir->d_namlen-4] = '\0';
                printf("%s\n", dir->d_name);
                count ++;
            }
        }
        closedir(d);
    }
    if(count == 0){
        printf("Aucun labyrinthe sauvegarde\n");
    }
}

void save_labyrinthe(case_lab **lab, int row, int col, char * file_name){

    FILE *fichier;

    /*location of the save file*/
    char * file_path = (char*) malloc(sizeof(file_name) + sizeof(char) * 15);
    strcpy(file_path, "../save/");
    strcat(file_path, file_name);
    strcat(file_path, ".cfg");

    fichier = fopen (file_path, "wb");

    fwrite(&row, sizeof(int), 1, fichier);
    fwrite(&col, sizeof(int), 1, fichier);

    for (int i = 0; i < row; i++) {
        fwrite(lab[i], col*sizeof(case_lab), 1, fichier);
    }

    if(fwrite != 0)
        printf("Le labyrinthe a bien ete enregistre !\n");
    else
        printf("Erreur lors de l'enregistrement du labyrinthe !\n");

    /* close file */
    fclose (fichier);

}

int is_valid_name(char * file_name){
    for (int i = 0; i < strlen(file_name); i++){
        if (file_name[i] == '/' || file_name[i] == '\\'){
            return 0;
        }
        if (file_name[i] == ' '){
            file_name[i] = '_';
        }
    }
    return 1;
}

case_lab ** load_labyrinthe_from_file(char * file_name, int *row, int *col){

    FILE *fichier;

    /*location of the save file*/
    char * file_path = (char*) malloc(sizeof(file_name) + sizeof(char) * 15);
    strcpy(file_path, "../save/");
    strcat(file_path, file_name);
    strcat(file_path, ".cfg");

    if( access( file_path, F_OK ) != -1 ) {

        fichier = fopen(file_path, "rb");

        fread(row, sizeof(int), 1, fichier);
        fread(col, sizeof(int), 1, fichier);

        printf("Row : %d , Col : %d \n", *row, *col);

        case_lab ** lab = (case_lab **) malloc( *row * sizeof(case_lab));

        for (int i = 0; i < *row; i++) {
            case_lab * data_row = (case_lab *) malloc( *col * sizeof(case_lab));

            fread(data_row, *col * sizeof(case_lab) , 1, fichier);

            lab[i] = data_row;
        }



        fclose(fichier);

        return lab;

    } else {
        // file doesn't exist
        printf("Fichier introuvable !");
        return NULL;
    }

}