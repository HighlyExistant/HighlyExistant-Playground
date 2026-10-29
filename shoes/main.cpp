#include <utility>
#include <random>
#include <ctime>
#include "render.hpp"

enum class Ordering : int {
    Lesser,
    Greater,
    Eq,
};

std::pair<Ordering, Ordering> check_shoes(int a_x, int a_y, int u_x, int u_y) {
    Ordering w_o = u_x < a_x ? Ordering::Greater : (u_x > a_x ? Ordering::Lesser : Ordering::Eq);
    Ordering h_o = u_y < a_y ? Ordering::Greater : (u_y > a_y ? Ordering::Lesser : Ordering::Eq);
   
    return std::make_pair(w_o, h_o);
}

int main(int argc, char const *argv[])
{
    int width = 8;
    int height = 8;
    if (argc >= 2)
    {
        width = atoi(argv[1]);
    }
    if (argc == 3)
    {
        height = atoi(argv[2]);
    }
    
    
    srand(time(0));
    int a_x = (rand()%width) + 1;
    int a_y = (rand()%height) + 1;
    // printf("%d %d\n", a_x, a_y);
    printf("Find a number in the range of [1, %d] x [1, %d]\n", width, height);

    int attempts = 0;
    ShoeRendererInfo render_info = {};
    render_info.width = width;
    render_info.height = height;
    render_info.left_range = make_range(0, 0);
    render_info.right_range = make_range(width+1, width+1);
    render_info.bottom_range = make_range(0, 0);
    render_info.up_range = make_range(height+1, height+1);

    while (true)
    {
        int u_x = -1, u_y = -1;
        scanf("%d %d", &u_x, &u_y);
        if (u_x > width || u_x < 1)
        {
            printf("Width must be within [1, %d]", width);
            continue;
        }
        if (u_y > height || u_y < 1)
        {
            printf("Height must be within [1, %d]", height);
            continue;
        }
        
        std::pair<Ordering, Ordering> ordering = check_shoes(a_x, a_y, u_x, u_y);
        switch (ordering.first)
        {
        case Ordering::Lesser:
            printf("Width is lesser\n");
            render_info.right_range.start = std::min(render_info.right_range.start, u_x-1);
            break;
        case Ordering::Greater:
            render_info.left_range.end = std::max(render_info.left_range.end, u_x+1);
            printf("Width is greater\n");
            break;
        case Ordering::Eq:
            render_info.left_range.end = a_x;
            render_info.right_range.start = a_x;
            printf("Width is equal\n");
            break;
        default:
            break;
        }
        switch (ordering.second)
        {
        case Ordering::Lesser:
            render_info.up_range.start = std::min(render_info.up_range.start, u_y-1);
            printf("Height is lesser\n");
            break;
        case Ordering::Greater:
            render_info.bottom_range.end = std::max(render_info.bottom_range.end, u_y+1);
            printf("Height is greater\n");
            break;
        case Ordering::Eq:
            printf("Height is equal\n");
            render_info.bottom_range.end = a_y;
            render_info.up_range.start = a_y;
            break;
        default:
            break;
        }
        
        render_shoes(render_info);
        attempts += 1;
        if (u_x == a_x && u_y == a_y)
        {
            printf("Congratulations its (%d, %d). Found in %d tries", a_x, a_y, attempts);
            break;
        }
    }
    
    return 0;
}
