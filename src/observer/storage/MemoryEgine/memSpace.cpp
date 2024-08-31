#include "/root/miniob/src/observer/common/rc.h"
#include "/root/miniob/src/observer/common/mm/mem_pool.h"
#include "/root/miniob/src/observer/storage/MemoryEgine/memPage.h"
class MemSpace{
public:
     MemSpace();
     ~MemSpace();
     RC init(int pool_num);
     //MemPage * alloc(int buffer_pool_id, PageNum page_num);
     //RC free(int buffer_pool_id, PageNum page_num, Frame *frame);
     //RC free_internal(const FrameId &frame_id, Frame *frame);
private:
     common::MemPoolSimple<MemPage> allocator_;
};

//BPFrameManager::BPFrameManager(const char *name) : allocator_(name) {}
// 初始化内存池,每个pool的大小是默认的大小
RC MemSpace::init(int pool_num)
{
  int ret = allocator_.init(false, pool_num);
  if (ret == 0) {
     std::cout<<"SUCCESS"<<"\n";
     return RC::SUCCESS;
     }
     std::cout<<"NOMEM"<<"\n";
     return RC::NOMEM;
}
/*
MemPage *MemSpace::alloc(int buffer_pool_id, PageNum page_num)
{
  FrameId frame_id(buffer_pool_id, page_num);

  lock_guard<mutex> lock_guard(lock_);

  Frame                      *frame = get_internal(frame_id);
  if (frame != nullptr) {
    return frame;
  }

  frame = allocator_.alloc();
  if (frame != nullptr) {
    ASSERT(frame->pin_count() == 0, "got an invalid frame that pin count is not 0. frame=%s", 
           frame->to_string().c_str());
    frame->set_buffer_pool_id(buffer_pool_id);
    frame->set_page_num(page_num);
    frame->pin();
    frames_.put(frame_id, frame);
  }
  return frame;
}

RC MemSpace::free(int buffer_pool_id, PageNum page_num, Frame *frame)
{
  FrameId frame_id(buffer_pool_id, page_num);

  lock_guard<mutex> lock_guard(lock_);
  return free_internal(frame_id, frame);
}

RC MemSpace::free_internal(const FrameId &frame_id, Frame *frame)
{
  Frame                *frame_source = nullptr;
  [[maybe_unused]] bool found        = frames_.get(frame_id, frame_source);
  ASSERT(found && frame == frame_source && frame->pin_count() == 1,
      "failed to free frame. found=%d, frameId=%s, frame_source=%p, frame=%p, pinCount=%d, lbt=%s",
      found, frame_id.to_string().c_str(), frame_source, frame, frame->pin_count(), lbt());

  frame->set_page_num(-1);
  frame->unpin();
  frames_.remove(frame_id);
  allocator_.free(frame);
  return RC::SUCCESS;
}
*/

int main(){
     MemSpace mem;
     mem.init(1);

}