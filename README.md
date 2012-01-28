**Simple C++ Smart Pointer Classes**

**owned_ptr** - ownership aware auto-deleting pointer.  
**counted_ptr** - simple reference counted pointer. **STL compatible**.  
**linked_ptr** - simple reference linked pointer (like reference counting, just using a linked list of the references, instead of their count.) **STL compatible**.  
**copied_ptr** - simple copy-on-create/assign pointer. **STL compatible**.  
**cow_ptr** - simple copy-on-write pointer. Implemented with reference counting (before write). **STL compatible**.  
**autocreate_ptr** - simple create-on-access pointer. Useful for implementing the Singleton pattern.  

For an introduction to smart pointers and an explanation of their use, see my article [Smart Pointers - What, Why, Which?](http://ootips.org/yonat/4dev/smart-pointers.html)  
For more rigorous smart pointers, please use [boost.org](http://www.boost.org/doc/libs/1_48_0/libs/smart_ptr/smart_ptr.htm)