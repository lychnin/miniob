database->page->table->record

database：分配mem_pool，支持内存池的扩展

database中：
table->record
page存放table，按record存储

hash索引

使SQL引擎可以主动选择调用不同的引擎


磁盘数据库中：
table存在文件中，record都在文件中存着


Table->insert_record:
  rc    = record_handler_->insert_record(record.data(), table_meta_.record_size(), &record.rid());

RecordPageHandler record_page_handler;
    recordFileHandler.insert_record->record_page_handler.insert_record

table->recordFileRecord->record_page_handler->insert_record

存到一个文件里，文件的pagenum存在free_pages，再在文件里按空位置存record

set_rid可设置rid，但暂且还不知道在哪设置的

实现思路：
1.先分配内存
2.在内存中划分page
3.在page中存放record
4.Table以record层面操作