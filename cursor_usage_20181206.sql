-------------造数据
-------根据phone_service表中现有的数据，造到tagentcalltransfer表中
-------游标用法
declare 
   cursor a1 is select * from phone_service t;
   v_service   phone_service%rowtype;
begin 
   open a1 ;
   loop
     fetch a1 into v_service;
     exit when a1%notfound;
          insert into tagentcalltransfer(l_id,d_date,l_agent,l_type,c_result,l_target,c_custno,c_phone,c_ischeck,c_memo,l_serialno,c_direction)
          values(seq_tagentcalltransfer.nextval,v_service.d_date,v_service.c_agentid,v_service.C_ACCOTYPE,0,6666,v_service.c_acco,v_service.c_phone,0,'abc',v_service.l_serialno,v_service.c_calltype);  
   end loop;
   close a1;
end;
/
