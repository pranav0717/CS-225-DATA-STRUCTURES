/* Your code here! */
#include "dsets.h"
using namespace std;

void DisjointSets::addelements(int num) {
  for (int i = 0; i < num; i++) {
    elements.push_back(-1);
  }
}

int DisjointSets::find(int elem) {
  int root = elem;

  while (elements[root] >= 0) {
    root = elements[root];
  }

  while (elem != root) {
    int parent = elements[elem];
    elements[elem] = root;
    elem = parent;
  }

  return root;
}

void DisjointSets::setunion(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);

  if (rootA == rootB) {
    return;
  }

  int sizeA = -elements[rootA];
  int sizeB = -elements[rootB];
  int newSize = sizeA + sizeB;

  if (sizeA < sizeB) {
    elements[rootB] = rootA;
    elements[rootA] = -newSize;
  } else {
    elements[rootA] = rootB;
    elements[rootB] = -newSize;
  }
}

int DisjointSets::size(int elem) {
  int root = find(elem);
  return -elements[root];
}







