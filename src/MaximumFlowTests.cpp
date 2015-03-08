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

   static void complexFlowTest()
   {
      CapacityGraph g(8);

      g.addEdge({ 0, 1, 10. });
      g.addEdge({ 0, 2, 5. });
      g.addEdge({ 0, 3, 15. });

      g.addEdge({ 1, 2, 4. });
      g.addEdge({ 2, 3, 4. });

      g.addEdge({ 1, 4, 8. });
      g.addEdge({ 1, 5, 15. });
      g.addEdge({ 2, 5, 8. });
      g.addEdge({ 3, 6, 16. });

      g.addEdge({ 4, 5, 15. });
      g.addEdge({ 5, 6, 15. });
      g.addEdge({ 6, 2, 6. });

      g.addEdge({ 4, 7, 10. });
      g.addEdge({ 5, 7, 10. });
      g.addEdge({ 6, 7, 10. });

      assert(28. == computeMaximumFlow(g, 0, 7));
   }

   void maximumFlowTests()
   {
      trivialGraphTest();
      diamondGraphTest();
      complexFlowTest();
   }
}
