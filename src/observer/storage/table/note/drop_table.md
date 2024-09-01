指令->parser_stage->handle_request->生成一个数据结构ParsedSqlNode->这个数据结构在parser_defs.h中定义->解析之后就到了resolve阶段->resolve_stage.cpp->handle_request->解析成一个语句  sql_event->set_stmt(stmt);->执行阶段execute_create_table.cpp->调用db.cpp的create_table函数->调用table.cpp的create_table函数->建表完成后返回到db再返回到executor


base_Dir存放文件的位置
创建一个元数据文件
将元数据序列化之后写入元数据文件
创建一个数据文件
record_handler管理行数据


