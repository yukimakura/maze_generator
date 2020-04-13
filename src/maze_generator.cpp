#include "maze_generator.hpp"


maze_generator::Point_ maze_generator::gen_random_point(){
    std::random_device rnd;
    Point_ p;

    p.x = abs(rnd());
    p.x = 1 + (p.x % (width_size_ - 1)) + (p.x % 2); //width_size_ - 1の−1は配列のバイアス(0スタートより)

    p.y = abs(rnd());
    p.y = 1 + (p.y % (height_size_ - 1)) + (p.y % 2);

    return p;
}

maze_generator::Dir_ maze_generator::gen_rnd_dir_(){
    std::random_device rnd;
    Dir_ dir;
    switch(abs(rnd() % 4)){
        case 0 :
            dir = up;
            break;
        case 1 :
            dir = down;
            break;
        case 2 :
            dir = left;
            break;
        default :
            dir = right;
            break;
    }

    return dir;
}

bool maze_generator::dig_map_(){
    Dir_ dir = gen_rnd_dir_();
    switch (dir)
    {
    case up:
        if(now_point.y - 2 < 1){
            return false;
        }else{
            if(map_[now_point.y-2][now_point.x] == false){
                return false;
            }else{
                map_[now_point.y-1][now_point.x] = false;
                map_[now_point.y-2][now_point.x] = false;
                now_point.y -= 2;

                return true;
            }
        }
        break;

        
    case left:
        if(now_point.x - 2 < 1){
            return false;
        }else{
            if(map_[now_point.y][now_point.x-2] == false){
                return false;
            }else{
                map_[now_point.y][now_point.x-1] = false;
                map_[now_point.y][now_point.x-2] = false;
                now_point.x -= 2;

                return true;
            }
        }
        break;

    case down:
        if(now_point.y + 2 > height_size_){
            return false;
        }else{
            if(map_[now_point.y+2][now_point.x] == false){
                return false;
            }else{
                map_[now_point.y+1][now_point.x] = false;
                map_[now_point.y+2][now_point.x] = false;
                now_point.y += 2;

                return true;
            }
        } 
        break;
        
    default:
        if(now_point.x + 2 > width_size_){
            return false;
        }else{
            if(map_[now_point.y][now_point.x+2] == false){
                return false;
            }else{
                map_[now_point.y][now_point.x+1] = false;
                map_[now_point.y][now_point.x+2] = false;
                now_point.x += 2;

                return true;
            }
        }
        break;
    }
}

bool maze_generator::judge_road_(Point_ p){
    return !map_[p.y][p.x];
}


void maze_generator::rem_rnd_point_from_map(){
    Point_ rnd_point = gen_random_point();
    map_[rnd_point.y][rnd_point.x] = false;

    std::cout << rnd_point.x << "," << rnd_point.y << std::endl;
}

void maze_generator::create_maze(){
    // map_[now_point.y][now_point.x] = false;
    while(dig_map_()){
        // point_history_.push_back(now_point);
    }
    Point_ buff_p;
    do{
        buff_p = gen_random_point();maze_generator::
    }
    while(!judge_road_(buff_p));
    now_point = buff_p;
    
}


void maze_generator::print_map(){
    for(std::vector<bool> v : map_){
        for(bool b : v){
            if(b){maze_generator::
                std::cout << " ■";
            }else{
                std::cout << " □";
            }
        }
        std::cout << std::endl;
    }
}
