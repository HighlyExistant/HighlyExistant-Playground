#pragma once
#include <cassert>
#include <iostream>
typedef struct OpenRange
{
    int start;
    int end;
} range_t;

range_t make_range(int start, int end)
{
    // assert(start <= end && "Range must be valid");
    return { start, end };
}

void printf_range(range_t r)
{
    // assert(start <= end && "Range must be valid");
    printf("(%d, %d)\n", r.start, r.end);
}

bool within_range(range_t range, int num)
{
    bool value = range.start < num && num < range.end;
    // if (value)
    // {
    //     printf("%d in (%d,%d)\n", num, range.start, range.end);
    // }
    
    return value;
}

typedef struct ShoeRendererInfo
{
    range_t left_range;
    range_t right_range;
    range_t up_range;
    range_t bottom_range;
    int width;
    int height;
} ShoeRendererInfo_t;

void render_shoes(ShoeRendererInfo &render_info)
{
    for (size_t j = 1; j < render_info.height+1; j++)
    {
        printf("Fila %d: ", j);
        for (size_t i = 1; i < render_info.width+1; i++)
        {
            if (within_range(render_info.left_range, i) || within_range(render_info.right_range, i) || within_range(render_info.up_range, j) || within_range(render_info.bottom_range, j))
            {
                printf("[X] ");
            }
            else
            {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}