#include "BinarySearchTests.h"
#include "ConnectedComponentTests.h"
#include "EncodingTests.h"
#include "GraphSearchTests.h"
#include "GraphTests.h"
#include "LinkedListTests.h"
#include "MaximumFlowTests.h"
#include "PriorityQueueTests.h"
#include "SetTests.h"
#include "ShortestPathTests.h"
#include "SimplexTests.h"
#include "SortTests.h"
#include "StringTrieTests.h"
#include "StringSortTests.h"
#include "SpanningTreeTests.h"
#include "SubStringSearchTests.h"
#include "TopologicalSortTests.h"
#include "UnionFindTests.h"
#include <iostream>
#include <string>

using namespace algorithm;


static bool runPerformanceTests(std::string const& title)
{
   std::cout << std::endl << "Run performance test on " << title << "? ";
   char res;
   std::cin >> res;
   return res == 'y';
}


int main()
{
   binarySearchTests();
   linkedListTests();
   graphTests();
   graphSearchTests();
   connectedComponentsTests();
   maximumFlowTests();
   shortestPathTests();
   topologicalSortTests();
   spanningTreeTests();
   setTests();
   stringSortingTests();
   stringTrieTests();
   simplexTests();

   unionFindTests();
   unionFindExample();
   priorityQueueTests();
   sortingTests();
   subStringSearchTests();
   bitStreamTest();
   runLengthEncodingTests();
   huffmanEncodingTests();

   if (runPerformanceTests("graphs"))
   {
      graphSearchPerfTests();
      topologicalSortPerfTests();
      shortestPathPerformanceTests();
      unionFindVsCCPerfTests();
      spanningTreePerfTests();
   }

   if (runPerformanceTests("collections"))
   {
      setPerfTests();
      stringTriePerfTests();
   }

   if (runPerformanceTests("sorts"))
   {
      stringSortingPerfTests();
      sortingPerfTests();
   }

   if (runPerformanceTests("string searches"))
   {
      subStringSearchPerfTests();
      system("PAUSE");
   }
}
