/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <deque>

#include <cmath>
using namespace std;

template <int Dim>
bool smallerDimVal(const Point<Dim>& first, const Point<Dim>& second, int curDim) {
     /**
     * @todo Implement this function!
     */                            
    if(first[curDim] < second[curDim]){
      return true;
    }
    else if(first[curDim] > second[curDim]){
      return false;
    }
    return first < second;
}

template <int Dim>
bool shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential)
{
    int target_dis = 0;
    int potential_dis = 0;

    for(int i = 0; i < Dim; i++){
        target_dis += ((currentBest[i] - target[i]) * (currentBest[i] - target[i]));
        potential_dis += ((target[i] - potential[i]) * (target[i] - potential[i]));
    }

    if (potential_dis < target_dis) {
        return true;
    }  
    else if (potential_dis > target_dis){
        return false;
    }

    return potential < currentBest;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints) {
    /**
     * @todo Implement this function!
     */
    if(Dim == 0){
      root = NULL;
      return;
    }
    vector<Point<Dim>> points(newPoints);
    size = newPoints.size();
    root = makeTree(points, 0, points.size()-1, 0);

}


template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::makeTree(vector<Point<Dim>> &points, int leftIdx, int rightIdx, int depth) {
    if (rightIdx < leftIdx) 
    {
    return nullptr; 
    }
    int medianIdx = (leftIdx + rightIdx) / 2;
    
    auto cmp = [d = depth](const auto& l, const auto& r) {
      return smallerDimVal(l, r, d);
    };
  
    select(points.begin() + leftIdx, points.begin() + rightIdx + 1, points.begin() + medianIdx , cmp);

    KDTreeNode* subroot = new KDTreeNode(points[medianIdx]);

    subroot->left = makeTree(points, leftIdx, medianIdx - 1, (depth + 1) % Dim);
    subroot->right = makeTree(points, medianIdx + 1, rightIdx, (depth + 1) % Dim);
    return subroot;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   copy(this->root, other.root);
   size = other.size;
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
    if(this != &rhs){
    delete *this;
    this = new KDTree(rhs);
    }
    return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  destroy(root);
}

template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode *subroot) {
    if (!subroot) 
    return;
    destroy(subroot->left);
    destroy(subroot->right);
    delete subroot;
}

////////////////////////////////////////////////
// template <int Dim>
// Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
// {
//     /**
//      * @todo Implement this function!
//      */

//     return Point<Dim>();
// }

///////////////////////////new///////////////////

/*

function findNearestNeighbor(query, dim, curRoot) :=
  if curRoot is bottom:
	return curRoot

  if query[dim] is on left side of curRoot[dim]:
	nearest = recurse on left subtree
  else:
	nearest = recurse on right subtree

  if curRoot is closer:
	update nearest

  radius = squaredDist(query, nearest) // radius between query & nearest
  splitDist = (curRoot -> point[dim] - query[dim]) ^ 2 // split distance on plane

  if radius >= splitDist:
	if already recursed on left:
	  tempNearest = recurse on right subtree
	else:
	  tempNearest = recurse on left subtree
	if tempNearest is closer:
	  update nearest
  return nearest

*/

template <int Dim>
double KDTree<Dim>::distance(Point<Dim> a, Point<Dim> b) const{
  double dis = 0;
  for (int i = 0; i < Dim; ++i) {
    dis += (b[i] - a[i]) * (b[i] - a[i]);
  }
  return dis;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearesthelper(const Point<Dim>& query, int dim, KDTreeNode* currRoot) const {
    if (currRoot->left == NULL && currRoot->right == NULL) {
        return currRoot->point;
    }

    Point<Dim> nearest;
    if (smallerDimVal(query, currRoot->point, dim)){
        if (currRoot->left) {
            nearest = findNearesthelper(query, (dim + 1) % Dim, currRoot->left);
        } else {
            nearest = currRoot->point;
        }
    } else {
        if (currRoot->right) {
            nearest = findNearesthelper(query, (dim + 1) % Dim, currRoot->right);
        } else {
            nearest = currRoot->point;
        }
    }

    if (shouldReplace(query, nearest, currRoot->point)) {
        nearest = currRoot->point;
    }

    double radius = distance(query, nearest);
    double splitDist = pow(query[dim] - currRoot->point[dim], 2);

    if (radius >= splitDist) {
        Point<Dim> tempNearest;
        if (smallerDimVal(query, currRoot->point, dim)) {
            if (currRoot->right) {
                tempNearest = findNearesthelper(query, (dim + 1) % Dim, currRoot->right);
            } else {
                tempNearest = currRoot->point;
            }
        } else {
            if (currRoot->left) {
                tempNearest = findNearesthelper(query, (dim + 1) % Dim, currRoot->left);
            } else {
                tempNearest = currRoot->point;
            }
        }

        if (shouldReplace(query, nearest, tempNearest)) {
            nearest = tempNearest;
        }
    }

    return nearest;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const {

    if(root == NULL){
    return Point<Dim>();
    }
    else {
    return findNearesthelper(query, 0, root);
    }
}
///////////////////////////new///////////////////
template <typename RandIter, typename Comparator>
RandIter partition(RandIter start1, RandIter end1, RandIter k1, Comparator cmp1)
{
    /**
     * @todo Implement this function!
     */   

    auto pivot = *k1;
    std::swap(*k1,*end1); //CEHCK

   RandIter save = start1;
for(RandIter i= start1; i != (end1) ; i++){
  if(cmp1(*i,pivot)){
    std:: swap(*save,*i); //CHECK
    save++;
  }   
}
std:: swap(*end1,*save); //CHECK
return save;
}

template <typename RandIter, typename Comparator>
void select(RandIter start, RandIter end, RandIter k, Comparator cmp)
{
    /**
     * @todo Implement this function!
     */    
     
     if(start == (end-1)) {
      return;
     }

     RandIter pivotIndex = start + floor(rand() % ((end-1) - start +1));

     pivotIndex = partition(start, (end-1), pivotIndex, cmp);

     if(k == pivotIndex){
      return;
     }
     else if(k < pivotIndex){
        return select(start, pivotIndex, k, cmp);
     }
     else {
     return select (pivotIndex + 1, end, k ,cmp);
     }
}

