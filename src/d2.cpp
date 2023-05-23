#include <iostream>
#include <string>
#include <fstream>

/* In hindsight, this would have been a little faster to write had I just 
 * made a class instead of using a struct. Very C-esque
 */
typedef struct Box 
{
    int32_t l, w, h;
} Box;

Box box_from_string(const std::string &dimensions) 
{
    Box box = {0, 0, 0};
    
    size_t last = 0;
    size_t x1 = dimensions.find("x");
    size_t x2 = dimensions.find("x", x1 + 1);
    box.l = std::stoi(dimensions.substr(0, dimensions.find("x")));
    box.w = std::stoi(dimensions.substr(x1 + 1, x2 - x1 - 1));
    box.h = std::stoi(dimensions.substr(x2 + 1));

    return box;
}

void print_box(const Box &box) 
{
    std::cout << "l: " << box.l << ", w: " << box.w << ", h: " << box.h << "\n";
}

int32_t box_surface_area(const Box &box)
{
    int32_t l = box.l;
    int32_t w = box.w;
    int32_t h = box.h;

    return 2*l*w + 2*l*h + 2*w*h;
}

int32_t box_smallest_face_area(const Box &box) 
{
    int32_t l = box.l;
    int32_t w = box.w;
    int32_t h = box.h;
    
    int32_t largest_length = 0;
    largest_length = (l > largest_length) ? l : largest_length;
    largest_length = (w > largest_length) ? w : largest_length;
    largest_length = (h > largest_length) ? h : largest_length;

    if (largest_length == 0) 
    {
        return 0;
    }

    return l*w*h/largest_length;
}

int32_t box_smallest_perimeter(const Box &box)
{
    int32_t l = box.l;
    int32_t w = box.w;
    int32_t h = box.h;
    
    int32_t largest_length = 0;
    largest_length = (l > largest_length) ? l : largest_length;
    largest_length = (w > largest_length) ? w : largest_length;
    largest_length = (h > largest_length) ? h : largest_length;
    
    return l + l + w + w + h + h - largest_length - largest_length;
}

int32_t box_volume(const Box &box)
{
    return box.l*box.w*box.h;
}

void part_a(const std::string &input_file)
{
    std::ifstream input(input_file);
    std::string dimensions;

    int32_t total_paper_area = 0;
    while (std::getline(input, dimensions)) 
    {
        Box box = box_from_string(dimensions);

        int32_t surface_area = box_surface_area(box);
        int32_t extra = box_smallest_face_area(box);
        int32_t paper_for_box = surface_area + extra;

        total_paper_area += paper_for_box;
    }

    std::cout << total_paper_area << "\n";
}

void part_b(const std::string &input_file)
{
    std::ifstream input(input_file);
    std::string dimensions;

    int32_t total_ribbon_length = 0;
    while (std::getline(input, dimensions)) 
    {
        Box box = box_from_string(dimensions);

        int32_t smallest_perimeter = box_smallest_perimeter(box);
        int32_t volume = box_volume(box);
        int32_t ribbon_for_box = smallest_perimeter + volume;

        total_ribbon_length += ribbon_for_box;
    }

    std::cout << total_ribbon_length << "\n";
}


int main()
{
    part_a("inputs/d2.txt");
    part_b("inputs/d2.txt");
}
