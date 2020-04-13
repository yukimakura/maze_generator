#include "maze_generator.hpp"


int main(int argc,char *argv[]){
    if(argc != 3){
        std::cout << "第一引数には横幅、第二引数には縦幅を指定してください" << std::endl;
        return -1;
    }
    maze_generator mg(atoi(argv[1]),atoi(argv[2]));
    // mg.rem_rnd_point_from_map();
    for(int a = 0 ; a < atoi(argv[1])*atoi(argv[2])*10 ;a++){
        mg.create_maze();

    }
    mg.print_map();
    return 0;
}