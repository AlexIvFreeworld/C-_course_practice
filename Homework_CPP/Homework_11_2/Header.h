#include <iostream>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
#ifndef VIDEO_H
#define VIDEO_H
struct video {
	string name;
	string producer;
	string genre;
	int top;
	double price;
	int ID = 0;
};
#endif
#ifndef LIST_VIDEO_H
#define LIST_VIDEO_H
struct List_video {
	video *p_to_arr_video;
	int num_video;
	int stat_ID;
};
#endif
void create_new_video(List_video *L_video_1, string name, string producer, string genre, int top, double price);
void show_all_video(List_video *L_video_1);
void add_video_to_file(List_video *L_video_1, string file_name);
void add_video_from_file(List_video *L_video_1, string file_name);
int num_string_in_file(string file_name);