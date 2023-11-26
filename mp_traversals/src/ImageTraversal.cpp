#include <cmath>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "Point.h"
#include <vector>
#include "ImageTraversal.h"
#include <algorithm>

namespace Traversals {
  /**
  * Calculates a metric for the difference between two pixels, used to
  * calculate if a pixel is within a tolerance.
  *
  * @param p1 First pixel
  * @param p2 Second pixel
  * @return the difference between two HSLAPixels
  */
  double calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
    double h = fabs(p1.h - p2.h);
    double s = p1.s - p2.s;
    double l = p1.l - p2.l;

    // Handle the case where we found the bigger angle between two hues:
    if (h > 180) { h = 360 - h; }
    h /= 360;

    return sqrt( (h*h) + (s*s) + (l*l) );
  }
  
  /**
  * Adds a Point for the bfs traversal to visit at some point in the future.
  * @param work_list the structure which stores the list of points which need to be visited by the traversal
  * @param point the point to be added
  */
  void bfs_add(std::deque<Point> & work_list, const Point & point) {
    /** @todo [Part 1] */
    work_list.push_back(point);
  }

  /**
  * Adds a Point for the dfs traversal to visit at some point in the future.
  * @param work_list the structure which stores the list of points which need to be visited by the traversal
  * @param point the point to be added
  */
  void dfs_add(std::deque<Point> & work_list, const Point & point) {
    /** @todo [Part 1] */
    work_list.push_back(point);
  }

  /**
  * Removes and returns the current Point in the bfs traversal
  * @param work_list the structure which stores the list of points which need to be visited by the traversal
  */
  Point bfs_pop(std::deque<Point> & work_list) {
    /** @todo [Part 1] */
    Point p = work_list.front();
    work_list.pop_front();
    return p;
  }

  /**
  * Removes and returns the current Point in the dfs traversal
  * @param work_list the structure which stores the list of points which need to be visited by the traversal
  */
  Point dfs_pop(std::deque<Point> & work_list) {
    /** @todo [Part 1] */
    Point p = work_list.back();
    work_list.pop_back();
    return p;
  }

  /**
  * Initializes a ImageTraversal on a given `png` image,
  * starting at `start`, and with a given `tolerance`.
  * @param png The image this traversal is going to traverse
  * @param start The start point of this traversal
  * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
  * it will not be included in this traversal
  * @param traversal_add a function pointer to an implemented function which takes in a reference to the work list
  * and the point to be added
  * @param traversal_pop a function pointer to an implemented function which takes in a reference to the work list
  * and returns the next point to be processed in the traversal
  */
  ImageTraversal::ImageTraversal(const PNG & png, const Point & start, double tolerance, add_function traversal_add, pop_function traversal_pop) {  
    /** @todo [Part 1] */
    png_=png;
    start_=start;
    tolerance_ =tolerance;
    traversal_add_ = traversal_add;
    traversal_pop_= traversal_pop;
  }

 ImageTraversal::Iterator::Iterator(const PNG & png, const Point & start, double tolerance, add_function traversal_add, pop_function traversal_pop){
    png_ = png;
    start_ = start;
    curr_ = start;
    tolerance_ = tolerance;
    traversal_add_ = traversal_add;
    traversal_pop_ = traversal_pop;
    visited_.resize(png.height(), vector<bool>(png.width(),false));
    traversal_add_(work_list,curr_);
}


  /**
  * Returns an iterator for the traversal starting at the first point.
  */
  ImageTraversal::Iterator ImageTraversal::begin() {
    /** @todo [Part 1] */
    ImageTraversal::Iterator myiterator(png_,start_,tolerance_,traversal_add_,traversal_pop_);
    return myiterator;
  }
  /**
  * Returns an iterator for the traversal one past the end of the traversal.
  */
  ImageTraversal::Iterator ImageTraversal::end() {
    /** @todo [Part 1] */
    return ImageTraversal::Iterator();
  }

  /**
  * Default iterator constructor.
  */
  ImageTraversal::Iterator::Iterator() {
    /** @todo [Part 1] */
    curr_ = Point(-201,-201);
  }


  /**
  * Iterator increment opreator.
  *
  * Advances the traversal of the image.
  */

// try 3
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
    /** @todo [Part 1] */
    if(curr_.x != (unsigned)-201){
        visited_[curr_.y][curr_.x] = true;
    }
    
    Point mleft = Point(curr_.x-1,curr_.y);
    Point mright = Point(curr_.x+1,curr_.y);
    Point mup = Point(curr_.x,curr_.y-1);
    Point mdown = Point(curr_.x,curr_.y+1);

    if(Valid(mright)){
      traversal_add_(work_list,mright);

    }
    if(Valid(mdown)){
      traversal_add_(work_list,mdown);

    }
    if(Valid(mleft)){
      traversal_add_(work_list,mleft);

    }
    if(Valid(mup)){
      traversal_add_(work_list,mup);

    }
    if(work_list.empty() == true){
      curr_ = Point(-201,-201);
    }
    if(work_list.empty() == false){
      curr_ = traversal_pop_(work_list);
    }
    while(curr_.x != (unsigned)-201 && visited_[curr_.y][curr_.x] == true){
      if(work_list.empty() == false){
      curr_ = traversal_pop_(work_list);
      }
      if(work_list.empty() == true){
      curr_ = Point(-201,-201);
    }
    }
    return *this;
  }




bool ImageTraversal::Iterator::Valid(const Point &p) {

  for (int i = 0; i < 2; i++) {
    int coord;
    int limit;
    if (i == 0) {
      coord = p.x;
      limit = png_.width();
    } else {
      coord = p.y;
      limit = png_.height();
    }
    if (coord < 0 || coord >= limit) {
      return false;
    }
  }

  if (calculateDelta(png_.getPixel(p.x, p.y), png_.getPixel(start_.x, start_.y)) < tolerance_) {
    return true;
  }

  return false;
}



  /**
  * Iterator accessor opreator.
  *
  * Accesses the current Point in the ImageTraversal.
  */
  Point ImageTraversal::Iterator::operator*() {
    /** @todo [Part 1] */
    return curr_;
  }

  /**
  * Iterator inequality operator.
  *
  * Determines if two iterators are not equal.
  */
  bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
    /** @todo [Part 1] */
    if(work_list != other.work_list){
      return true;
    }
    else 
    {
      return false;
    }
}
}
