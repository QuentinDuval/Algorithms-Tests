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

   void maximumFlowTests()
   {
      trivialGraphTest();
   }
}
