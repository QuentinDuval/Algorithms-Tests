#include "EncodingTests.h"

#include "BitStream.h"
#include "HuffmanEncoding.h"
#include "RunLengthEncoding.h"

#include <cassert>
#include <iostream>


namespace algorithm
{
   void bitStreamTest()
   {
      BitStream stream;
      stream.writeBit(true);
      stream.writeBit(false);
      stream.writeChar('c');
      assert(true == stream.readBit());
      assert(false == stream.readBit());
      assert('c' == stream.readChar());
   }

   //--------------------------------------------------------------------------

   void runLengthEncodingTests()
   {
      std::cout << "[Tests] RunLengthEncoding (ratios)" << std::endl;

      RunLengthEncoding encoding;
      BitStream bitStream;
      size_t size = 100;

      std::cout << " - All ones: ";
      std::string allOnes(size, 0xff);
      encodeWith(encoding, allOnes, bitStream);
      std::cout << bitStream.toRead() / (8.0 * allOnes.size()) << std::endl;
      assert(allOnes == decodeWith(encoding, bitStream));

      std::cout << " - Half ones: ";
      std::string halfOnes(size, 0xf0);
      encodeWith(encoding, halfOnes, bitStream);
      std::cout << bitStream.toRead() / (8.0 * allOnes.size()) << std::endl;
      assert(halfOnes == decodeWith(encoding, bitStream));

      std::cout << " - Interleaved: ";
      std::string interverted(size, 0x55);
      encodeWith(encoding, interverted, bitStream);
      std::cout << bitStream.toRead() / (8.0 * allOnes.size()) << std::endl;
      assert(interverted == decodeWith(encoding, bitStream));
   }

   //--------------------------------------------------------------------------

   void huffmanEncodingTests()
   {
      HuffmanEncoding encoding;
      BitStream bitStream;

      std::string adn = "ATACGCGTACGTAGCATCGCGTAATATTAGCTAGC";
      encodeWith(encoding, adn, bitStream);
      std::cout << bitStream.toRead() / (8.0 * adn.size()) << std::endl;
      assert(adn == decodeWith(encoding, bitStream));
   }
}
