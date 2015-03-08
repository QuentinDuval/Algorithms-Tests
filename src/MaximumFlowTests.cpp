#include "MaximumFlowTests.h"

#include "CapacityGraph.h"
#include "MaximumFlow.h"

#include <assert.h>
#include <iostream>


namespace algorithm
{
   static void trivialGraphTest()
   {
      CapacityGraph g(3);
      g.addEdge({ 0, 1, 2. });
      g.addEdge({ 1, 2, 1. });
      assert(1. == computeMaximumFlow(g, 0, 2));
      assert(2. == computeMaximumFlow(g, 0, 1));
   }

   static void diamondGraphTest()
   {
      CapacityGraph g(4);
      g.addEdge({ 0, 1, 1000. });
      g.addEdge({ 0, 2, 1000. });
      g.addEdge({ 1, 2, 1. });
      g.addEdge({ 1, 3, 1000. });
      g.addEdge({ 2, 3, 1000. });
      assert(2000. == computeMaximumFlow(g, 0, 3));
   }

   void maximumFlowTests()
   {
      trivialGraphTest();
      diamondGraphTest();
   }
}
