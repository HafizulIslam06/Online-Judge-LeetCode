/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
*/


class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc,int newColor,int rows,int cols,int source)
    {
        if(sr<0 || sr>=rows || sc<0 || sc>=cols)
            return;
        else if(image[sr][sc]!=source)
            return;

        image[sr][sc] = newColor;

        dfs(image,sr-1,sc,newColor,rows,cols,source);   //TOP
        dfs(image,sr+1,sc,newColor,rows,cols,source);   //DOWN
        dfs(image,sr,sc-1,newColor,rows,cols,source);   //LEFT
        dfs(image,sr,sc+1,newColor,rows,cols,source);   //RIGHT
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        if(newColor==image[sr][sc])
            return image;
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc];
        dfs(image,sr,sc,newColor,rows,cols,source);
        return image;
    }
};
