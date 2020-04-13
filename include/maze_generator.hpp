#include <iostream>
#include <vector>
#include <random>

class maze_generator{
    private:
        typedef struct{
            int x,y;
        }Point_;

        enum Dir_{
            up,down,left,right
        };

        int width_size_;
        int height_size_;
        std::vector< std::vector<bool> > map_;

        Point_ now_point;
        int dig_counter_;
        std::vector<Point_> point_history_;
        Point_ gen_random_point();
        Dir_ gen_rnd_dir_();

        bool dig_map_();
        bool judge_road_(Point_ p);

    public:
        maze_generator(int width_size, int height_size):dig_counter_(0),width_size_(width_size),height_size_(height_size){
            std::vector<bool> map_buffer;
            for(int w_cnt = 0; w_cnt < width_size+2; w_cnt++){ //+2は外壁
                map_buffer.push_back(true);
            }
            for (int h_cnt  = 0; h_cnt < height_size+2; h_cnt++){
                map_.push_back(map_buffer);
            }
            now_point = gen_random_point();
        }

        void rem_rnd_point_from_map();
        void create_maze();
        void print_map();
        
        std::vector< std::vector<bool> > get_map(){
            return map_;
        }
        
};