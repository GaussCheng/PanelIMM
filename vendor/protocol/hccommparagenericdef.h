
/*
 * File:   hccommparagenericdef.h
 * Author: xs
 *
 * Created on June 12, 2012, 1:53 PM
 */

#ifndef HCCOMMPARAGENERICDEF_H
#define	HCCOMMPARAGENERICDEF_H

#include "stdint.h"
#ifdef	__cplusplus
extern "C" {
#endif

#define STRUCE_SIZE(a,b) (b-a+1)

    /*! \brief 参数地址枚举 */
    typedef enum _ICAddr {
        ICAddr_BeginSection, //<参数地址开头哨兵0
        /***************************************************************************************/
        ICAddr_System_Para0, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para1, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para2, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para3, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para4, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para5, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para6, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para7, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para8, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para9, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para10, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para11, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para12, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para13, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para14, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para15, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para16, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para17, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para18, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para19, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para20, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para21, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para22, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para23, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para24, //<类型：内部；名字：系统参数；结构：SYSTEM_PARA；地址：system_addr；
        ICAddr_System_Para25, //<类型：预留；
        ICAddr_System_Para26, //<类型：预留；
        ICAddr_System_Para27, //<类型：预留；
        ICAddr_System_Para28, //<类型：预留；
        ICAddr_System_Para29, //<类型：预留；
        ICAddr_System_Para30, //<类型：预留；
        ICAddr_System_Para31, //<类型：预留；
        ICAddr_System_Para32, //<类型：预留；
        ICAddr_System_Para33, //<类型：预留；
        ICAddr_System_Para34, //<类型：预留；
        ICAddr_System_Para35, //<类型：预留；
        ICAddr_System_Para36, //<类型：预留；
        ICAddr_System_Para37, //<类型：预留；
        ICAddr_System_Para38, //<类型：预留；
        ICAddr_System_Para39, //<类型：预留；
        ICAddr_System_Para40, //<类型：预留；
        ICAddr_System_Para41, //<类型：预留；
        ICAddr_System_Para42, //<类型：预留；
        ICAddr_System_Para43, //<类型：预留；
        ICAddr_System_Para44, //<类型：预留；
        ICAddr_System_Para45, //<类型：预留；
        ICAddr_System_Para46, //<类型：预留；
        ICAddr_System_Para47, //<类型：预留；
        ICAddr_System_Para48, //<类型：预留；
        ICAddr_System_Para49, //<类型：预留；
        /***************************************************************************************/
        ICAddr_Action, //<动作地址1
        ICAddr_MoldBase_Para0, //<类型：模号；名字：关模一段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para1, //<类型：模号；名字：关模一段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para2, //<类型：系统；名字：关模一段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para3, //<类型：系统；名字：关模一段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para4, //<类型：模号；名字：关模二段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para5, //<类型：模号；名字：关模二段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para6, //<类型：系统；名字：关模二段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para7, //<类型：系统；名字：关模二段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para8, //<类型：模号；名字：关模三段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para9, //<类型：模号；名字：关模三段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para10, //<类型：系统；名字：关模三段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para11, //<类型：系统；名字：关模三段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para12, //<类型：模号；名字：关模四段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para13, //<类型：模号；名字：关模四段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para14, //<类型：系统；名字：关模四段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para15, //<类型：系统；名字：关模四段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para16, //<类型：模号；名字：关模五段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para17, //<类型：模号；名字：关模五段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para18, //<类型：系统；名字：关模五段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para19, //<类型：系统；名字：关模五段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para20, //<类型：模号；名字：关模六段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para21, //<类型：模号；名字：关模六段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para22, //<类型：系统；名字：关模六段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para23, //<类型：系统；名字：关模六段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para24, //<类型：模号；名字：关模七段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para25, //<类型：模号；名字：关模七段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para26, //<类型：系统；名字：关模七段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para27, //<类型：系统；名字：关模七段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para28, //<类型：模号；名字：关模八段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para29, //<类型：模号；名字：关模八段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para30, //<类型：系统；名字：关模八段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para31, //<类型：系统；名字：关模八段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para32, //<类型：模号；名字：低压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para33, //<类型：模号；名字：低压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para34, //<类型：系统；名字：低压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para35, //<类型：系统；名字：低压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para36, //<类型：模号；名字：高压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para37, //<类型：模号；名字：高压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para38, //<类型：系统；名字：高压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para39, //<类型：系统；名字：高压锁模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para40, //<类型：模号；名字：关模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para41, //<类型：系统；名字：关模；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para42, //<类型：模号；名字：；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para43, //<类型：模号；名字：；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para44, //<类型：模号；名字：；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para45, //<类型：预留
        ICAddr_MoldBase_Para46, //<类型：预留
        ICAddr_MoldBase_Para47, //<类型：预留
        ICAddr_MoldBase_Para48, //<类型：预留
        ICAddr_MoldBase_Para49, //<类型：预留

        ICAddr_MoldBase_Para50, //<类型：模号；名字：开模一段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para51, //<类型：模号；名字：开模一段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para52, //<类型：系统；名字：开模一段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para53, //<类型：系统；名字：开模一段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para54, //<类型：模号；名字：开模二段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para55, //<类型：模号；名字：开模二段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para56, //<类型：系统；名字：开模二段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para57, //<类型：系统；名字：开模二段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para58, //<类型：模号；名字：开模三段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para59, //<类型：模号；名字：开模三段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para60, //<类型：系统；名字：开模三段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para61, //<类型：系统；名字：开模三段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para62, //<类型：模号；名字：开模四段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para63, //<类型：模号；名字：开模四段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para64, //<类型：系统；名字：开模四段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para65, //<类型：系统；名字：开模四段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para66, //<类型：模号；名字：开模五段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para67, //<类型：模号；名字：开模五段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para68, //<类型：系统；名字：开模五段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para69, //<类型：系统；名字：开模五段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para70, //<类型：模号；名字：开模六段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para71, //<类型：模号；名字：开模六段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para72, //<类型：系统；名字：开模六段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para73, //<类型：系统；名字：开模六段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para74, //<类型：模号；名字：开模七段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para75, //<类型：模号；名字：开模七段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para76, //<类型：系统；名字：开模七段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para77, //<类型：系统；名字：开模七段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para78, //<类型：模号；名字：开模八段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para79, //<类型：模号；名字：开模八段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para80, //<类型：系统；名字：开模八段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para81, //<类型：系统；名字：开模八段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para82, //<类型：模号；名字：开模九段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para83, //<类型：模号；名字：开模九段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para84, //<类型：系统；名字：开模九段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para85, //<类型：系统；名字：开模九段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para86, //<类型：模号；名字：开模十段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para87, //<类型：模号；名字：开模十段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para88, //<类型：系统；名字：开模十段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para89, //<类型：系统；名字：开模十段；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para90, //<类型：模号；名字：开模；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para91, //<类型：系统；名字：开模；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para92, //<类型：模号；名字：；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para93, //<类型：模号；名字：；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
        ICAddr_MoldBase_Para94, //<类型：预留；
        ICAddr_MoldBase_Para95, //<类型：预留；
        ICAddr_MoldBase_Para96, //<类型：预留；
        ICAddr_MoldBase_Para97, //<类型：预留；
        ICAddr_MoldBase_Para98, //<类型：预留；
        ICAddr_MoldBase_Para99, //<类型：预留；

        ICAddr_MoldBase_Para100, //<类型：模号；名字：射出一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para101, //<类型：模号；名字：射出一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para102, //<类型：系统；名字：射出一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para103, //<类型：系统；名字：射出一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para104, //<类型：模号；名字：射出二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para105, //<类型：模号；名字：射出二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para106, //<类型：系统；名字：射出二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para107, //<类型：系统；名字：射出二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para108, //<类型：模号；名字：射出三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para109, //<类型：模号；名字：射出三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para110, //<类型：系统；名字：射出三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para111, //<类型：系统；名字：射出三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para112, //<类型：模号；名字：射出四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para113, //<类型：模号；名字：射出四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para114, //<类型：系统；名字：射出四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para115, //<类型：系统；名字：射出四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para116, //<类型：模号；名字：射出五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para117, //<类型：模号；名字：射出五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para118, //<类型：系统；名字：射出五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para119, //<类型：系统；名字：射出五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para120, //<类型：模号；名字：射出六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para121, //<类型：模号；名字：射出六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para122, //<类型：系统；名字：射出六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para123, //<类型：系统；名字：射出六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para124, //<类型：模号；名字：射出七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para125, //<类型：模号；名字：射出七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para126, //<类型：系统；名字：射出七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para127, //<类型：系统；名字：射出七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para128, //<类型：模号；名字：射出八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para129, //<类型：模号；名字：射出八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para130, //<类型：系统；名字：射出八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para131, //<类型：系统；名字：射出八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para132, //<类型：模号；名字：射出九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para133, //<类型：模号；名字：射出九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para134, //<类型：系统；名字：射出九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para135, //<类型：系统；名字：射出九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para136, //<类型：模号；名字：射出十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para137, //<类型：模号；名字：射出十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para138, //<类型：系统；名字：射出十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para139, //<类型：系统；名字：射出十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para140, //<类型：模号；名字：射出；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para141, //<类型：系统；名字：射出；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para142, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para143, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para144, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para145, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para146, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para147, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para148, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para149, //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para150, //<类型：模号；名字：保压一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para151, //<类型：模号；名字：保压一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para152, //<类型：系统；名字：保压一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para153, //<类型：系统；名字：保压一段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para154, //<类型：模号；名字：保压二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para155, //<类型：模号；名字：保压二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para156, //<类型：系统；名字：保压二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para157, //<类型：系统；名字：保压二段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para158, //<类型：模号；名字：保压三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para159, //<类型：模号；名字：保压三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para160, //<类型：系统；名字：保压三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para161, //<类型：系统；名字：保压三段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para162, //<类型：模号；名字：保压四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para163, //<类型：模号；名字：保压四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para164, //<类型：系统；名字：保压四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para165, //<类型：系统；名字：保压四段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para166, //<类型：模号；名字：保压五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para167, //<类型：模号；名字：保压五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para168, //<类型：系统；名字：保压五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para169, //<类型：系统；名字：保压五段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para170, //<类型：模号；名字：保压六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para171, //<类型：模号；名字：保压六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para172, //<类型：系统；名字：保压六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para173, //<类型：系统；名字：保压六段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para174, //<类型：模号；名字：保压七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para175, //<类型：模号；名字：保压七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para176, //<类型：系统；名字：保压七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para177, //<类型：系统；名字：保压七段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para178, //<类型：模号；名字：保压八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para179, //<类型：模号；名字：保压八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para180, //<类型：系统；名字：保压八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para181, //<类型：系统；名字：保压八段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para182, //<类型：模号；名字：保压九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para183, //<类型：模号；名字：保压九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para184, //<类型：系统；名字：保压九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para185, //<类型：系统；名字：保压九段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para186, //<类型：模号；名字：保压十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para187, //<类型：模号；名字：保压十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para188, //<类型：系统；名字：保压十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para189, //<类型：系统；名字：保压十段；结构：INJECT_IN_PARA；地址：inject_in_addr；
        ICAddr_MoldBase_Para190, //<类型：预留；
        ICAddr_MoldBase_Para191, //<类型：预留；
        ICAddr_MoldBase_Para192, //<类型：预留；
        ICAddr_MoldBase_Para193, //<类型：预留；
        ICAddr_MoldBase_Para194, //<类型：预留；
        ICAddr_MoldBase_Para195, //<类型：预留；
        ICAddr_MoldBase_Para196, //<类型：预留；
        ICAddr_MoldBase_Para197, //<类型：预留；
        ICAddr_MoldBase_Para198, //<类型：预留；
        ICAddr_MoldBase_Para199, //<类型：预留；

        ICAddr_MoldBase_Para200, //<类型：模号；名字：射前加料；结构：BEFORE_INJECT_CHARGE_PARA；地址：before_inject_charge_addr；
        ICAddr_MoldBase_Para201, //<类型：模号；名字：射前加料；结构：BEFORE_INJECT_CHARGE_PARA；地址：before_inject_charge_addr；
        ICAddr_MoldBase_Para202, //<类型：系统；名字：射前加料；结构：BEFORE_INJECT_CHARGE_PARA；地址：before_inject_charge_addr；
        ICAddr_MoldBase_Para203, //<类型：系统；名字：射前加料；结构：BEFORE_INJECT_CHARGE_PARA；地址：before_inject_charge_addr；
        ICAddr_MoldBase_Para204, //<类型：模号；名字：射前加料；结构：BEFORE_INJECT_CHARGE_PARA；地址：before_inject_charge_addr；
        ICAddr_MoldBase_Para205, //<类型：系统；名字：射前加料；结构：BEFORE_INJECT_CHARGE_PARA；地址：before_inject_charge_addr；
        ICAddr_MoldBase_Para206, //<类型：预留；
        ICAddr_MoldBase_Para207, //<类型：预留；
        ICAddr_MoldBase_Para208, //<类型：预留；

        ICAddr_MoldBase_Para209, //<类型：模号；名字：加料一段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para210, //<类型：模号；名字：加料一段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para211, //<类型：系统；名字：加料一段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para212, //<类型：系统；名字：加料一段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para213, //<类型：模号；名字：加料二段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para214, //<类型：模号；名字：加料二段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para215, //<类型：系统；名字：加料二段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para216, //<类型：系统；名字：加料二段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para217, //<类型：模号；名字：加料三段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para218, //<类型：模号；名字：加料三段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para219, //<类型：系统；名字：加料三段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para220, //<类型：系统；名字：加料三段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para221, //<类型：模号；名字：加料四段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para222, //<类型：模号；名字：加料四段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para223, //<类型：系统；名字：加料四段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para224, //<类型：系统；名字：加料四段；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para225, //<类型：模号；名字：加料；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para226, //<类型：系统；名字：加料；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para227, //<类型：模号；名字：；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para228, //<类型：模号；名字：；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para229, //<类型：模号；名字：；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para230, //<类型：系统；名字：；结构：CHARGE_PARA；地址：charge_addr；
        ICAddr_MoldBase_Para231, //<类型：预留；

        ICAddr_MoldBase_Para232, //<类型：模号；名字：；结构：COOL_PARA；地址：cool_addr；

        ICAddr_MoldBase_Para233, //<类型：模号；名字：前松退；结构：FRONT_SUCKBACK_PARA0；地址：front_suckback_addr；
        ICAddr_MoldBase_Para234, //<类型：模号；名字：前松退；结构：FRONT_SUCKBACK_PARA0；地址：front_suckback_addr；
        ICAddr_MoldBase_Para235, //<类型：系统；名字：前松退；结构：FRONT_SUCKBACK_PARA0；地址：front_suckback_addr；
        ICAddr_MoldBase_Para236, //<类型：系统；名字：前松退；结构：FRONT_SUCKBACK_PARA0；地址：front_suckback_addr；
        ICAddr_MoldBase_Para237, //<类型：模号；名字：前松退；结构：FRONT_SUCKBACK_PARA0；地址：front_suckback_addr；
        ICAddr_MoldBase_Para238, //<类型：系统；名字：前松退；结构：FRONT_SUCKBACK_PARA0；地址：front_suckback_addr；
        ICAddr_MoldBase_Para239, //<类型：预留

        ICAddr_MoldBase_Para240, //<类型：模号；名字：后松退；结构：AFTER_SUCKBACK_PARA；地址：after_suckback_addr；
        ICAddr_MoldBase_Para241, //<类型：模号；名字：后松退；结构：AFTER_SUCKBACK_PARA；地址：after_suckback_addr；
        ICAddr_MoldBase_Para242, //<类型：系统；名字：后松退；结构：AFTER_SUCKBACK_PARA；地址：after_suckback_addr；
        ICAddr_MoldBase_Para243, //<类型：系统；名字：后松退；结构：AFTER_SUCKBACK_PARA；地址：after_suckback_addr；
        ICAddr_MoldBase_Para244, //<类型：模号；名字：后松退；结构：AFTER_SUCKBACK_PARA；地址：after_suckback_addr；
        ICAddr_MoldBase_Para245, //<类型：系统；名字：后松退；结构：AFTER_SUCKBACK_PARA；地址：after_suckback_addr；
        ICAddr_MoldBase_Para246, //<类型：预留

        ICAddr_MoldBase_Para247, //<类型：模号；名字：顶进一段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para248, //<类型：模号；名字：顶进一段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para249, //<类型：系统；名字：顶进一段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para250, //<类型：系统；名字：顶进一段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para251, //<类型：模号；名字：顶进二段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para252, //<类型：模号；名字：顶进二段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para253, //<类型：系统；名字：顶进二段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para254, //<类型：系统；名字：顶进二段；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para255, //<类型：模号；名字：顶进；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para256, //<类型：系统；名字：顶进；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para257, //<类型：模号；名字：顶进；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
        ICAddr_MoldBase_Para258, //<类型：预留；

        ICAddr_MoldBase_Para259, //<类型：模号；名字：顶退一段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para260, //<类型：模号；名字：顶退一段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para261, //<类型：系统；名字：顶退一段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para262, //<类型：系统；名字：顶退一段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para263, //<类型：模号；名字：顶退二段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para264, //<类型：模号；名字：顶退二段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para265, //<类型：系统；名字：顶退二段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para266, //<类型：系统；名字：顶退二段；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para267, //<类型：模号；名字：顶退；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para268, //<类型：系统；名字：顶退；结构：EJECT_RET_PARA；地址：eject_ret_addr；
        ICAddr_MoldBase_Para269, //<类型：预留；
        ICAddr_MoldBase_Para270, //<类型：预留；

        ICAddr_MoldBase_Para271, //<类型：模号；名字：定模吹气1；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para272, //<类型：模号；名字：定模吹气1；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para273, //<类型：模号；名字：定模吹气2；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para274, //<类型：模号；名字：定模吹气2；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para275, //<类型：模号；名字：定模吹气3；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para276, //<类型：模号；名字：定模吹气3；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para277, //<类型：模号；名字：动模吹气1；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para278, //<类型：模号；名字：动模吹气1；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para279, //<类型：模号；名字：动模吹气2；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para280, //<类型：模号；名字：动模吹气2；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para281, //<类型：模号；名字：动模吹气3；结构：BLOW_PARA；地址：blow_addr；
        ICAddr_MoldBase_Para282, //<类型：模号；名字：动模吹气3；结构：BLOW_PARA；地址：blow_addr；

        ICAddr_MoldBase_Para283, //<类型：模号；名字：抽芯A入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para284, //<类型：模号；名字：抽芯A入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para285, //<类型：模号；名字：抽芯A入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para286, //<类型：模号；名字：抽芯A出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para287, //<类型：模号；名字：抽芯A出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para288, //<类型：模号；名字：抽芯A出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para289, //<类型：模号；名字：抽芯B入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para290, //<类型：模号；名字：抽芯B入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para291, //<类型：模号；名字：抽芯B入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para292, //<类型：模号；名字：抽芯B出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para293, //<类型：模号；名字：抽芯B出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para294, //<类型：模号；名字：抽芯B出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para295, //<类型：模号；名字：抽芯C入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para296, //<类型：模号；名字：抽芯C入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para297, //<类型：模号；名字：抽芯C入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para298, //<类型：模号；名字：抽芯C出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para299, //<类型：模号；名字：抽芯C出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para300, //<类型：模号；名字：抽芯C出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para301, //<类型：模号；名字：抽芯D入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para302, //<类型：模号；名字：抽芯D入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para303, //<类型：模号；名字：抽芯D入；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para304, //<类型：模号；名字：抽芯D出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para305, //<类型：模号；名字：抽芯D出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para306, //<类型：模号；名字：抽芯D出；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para307, //<类型：模号；名字：抽芯；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para308, //<类型：系统；名字：抽芯；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para309, //<类型：系统；名字：；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para310, //<类型：系统；名字：；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para311, //<类型：系统；名字：；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para312, //<类型：系统；名字：；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para313, //<类型：模号；名字：；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para314, //<类型：模号；名字：；结构：ALL_CORE_PARA；地址：core_addr；
        ICAddr_MoldBase_Para315, //<类型：模号；名字：；结构：ALL_CORE_PARA；地址：core_addr；

        ICAddr_MoldBase_Para316, //<类型：模号；名字：座进快速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para317, //<类型：模号；名字：座进快速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para318, //<类型：系统；名字：座进快速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para319, //<类型：系统；名字：座进快速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para320, //<类型：模号；名字：座进慢速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para321, //<类型：模号；名字：座进慢速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para322, //<类型：系统；名字：座进慢速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para323, //<类型：系统；名字：座进慢速；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para324, //<类型：模号；名字：座进；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para325, //<类型：系统；名字：座进；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para326, //<类型：模号；名字：座进；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
        ICAddr_MoldBase_Para327, //<类型：系统；名字：座进；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；

        ICAddr_MoldBase_Para328, //<类型：模号；名字：座退；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
        ICAddr_MoldBase_Para329, //<类型：模号；名字：座退；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
        ICAddr_MoldBase_Para330, //<类型：系统；名字：座退；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
        ICAddr_MoldBase_Para331, //<类型：系统；名字：座退；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
        ICAddr_MoldBase_Para332, //<类型：模号；名字：座退；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
        ICAddr_MoldBase_Para333, //<类型：系统；名字：座退；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
        ICAddr_MoldBase_Para334, //<类型：模号；名字：；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
        ICAddr_MoldBase_Para335, //<类型：预留；

        ICAddr_MoldBase_Para336, //<类型：模号；名字：手；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para337, //<类型：模号；名字：手；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para338, //<类型：模号；名字：手；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para339, //<类型：系统；名字：自；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para340, //<类型：系统；名字：自；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para341, //<类型：系统；名字：自；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para342, //<类型：模号；名字：调模；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para343, //<类型：模号；名字：调模；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para344, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para345, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para346, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para347, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para348, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para349, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para350, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para351, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para352, //<类型：系统；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
        ICAddr_MoldBase_Para353, //<类型：预留；
        ICAddr_MoldBase_Para354, //<类型：预留；

        ICAddr_MoldBase_Para355, //<类型：模号；名字：自清料射一；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para356, //<类型：模号；名字：自清料射一；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para357, //<类型：模号；名字：自清料射二；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para358, //<类型：模号；名字：自清料射二；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para359, //<类型：模号；名字：自清料松退；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para360, //<类型：模号；名字：自清料松退；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para361, //<类型：模号；名字：自清料加料；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para362, //<类型：模号；名字：自清料加料；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para363, //<类型：模号；名字：；结构：AUTOPURGE_PARA；地址：autopurge_addr；
        ICAddr_MoldBase_Para364, //<类型：预留；
        ICAddr_MoldBase_Para365, //<类型：预留；

        ICAddr_MoldBase_Para366, //<类型：系统；名字：；结构：AUTORUN_PARA；地址：autorun_addr；
        ICAddr_MoldBase_Para367, //<类型：系统；名字：；结构：AUTORUN_PARA；地址：autorun_addr；
        ICAddr_MoldBase_Para368, //<类型：模号；名字：；结构：AUTORUN_PARA；地址：autorun_addr；
        ICAddr_MoldBase_Para369, //<类型：模号；名字：；结构：AUTORUN_PARA；地址：autorun_addr；
        ICAddr_MoldBase_Para370, //<类型：预留；
        ICAddr_MoldBase_Para371, //<类型：预留；
        ICAddr_MoldBase_Para372, //<类型：预留；
        ICAddr_MoldBase_Para373, //<类型：预留；
        ICAddr_MoldBase_Para374, //<类型：预留；
        ICAddr_MoldBase_Para375, //<类型：预留；

        ICAddr_MoldBase_Para376, //<类型：模号；名字：；结构：FOECE_BULICATE_PARA；地址：force_lubricate_addr；
        ICAddr_MoldBase_Para377, //<类型：模号；名字：；结构：FOECE_BULICATE_PARA；地址：force_lubricate_addr；
        ICAddr_MoldBase_Para378, //<类型：预留；
        ICAddr_MoldBase_Para379, //<类型：预留；

        ICAddr_MoldBase_Para380, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para381, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para382, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para383, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para384, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para385, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para386, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para387, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para388, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para389, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para390, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para391, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para392, //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
        ICAddr_MoldBase_Para393, //<类型：预留；
        ICAddr_MoldBase_Para394, //<类型：预留；
        ICAddr_MoldBase_Para395, //<类型：预留；
        ICAddr_MoldBase_Para396, //<类型：预留；
        ICAddr_MoldBase_Para397, //<类型：预留；
        ICAddr_MoldBase_Para398, //<类型：预留；
        ICAddr_MoldBase_Para399, //<类型：预留；

        ICAddr_MoldBase_Para400, //<类型：模号；名字：；结构：ELECTRIC_EYE_PARA；地址：electric_eye_addr；
        ICAddr_MoldBase_Para401, //<类型：模号；名字：；结构：ELECTRIC_EYE_PARA；地址：electric_eye_addr；
        ICAddr_MoldBase_Para402, //<类型：预留；
        ICAddr_MoldBase_Para403, //<类型：预留；
        ICAddr_MoldBase_Para404, //<类型：预留；

        ICAddr_MoldBase_Para405, //<类型：系统；名字：；结构：MOTOR_PARA；地址：motor_addr；
        ICAddr_MoldBase_Para406, //<类型：系统；名字：；结构：MOTOR_PARA；地址：motor_addr；
        ICAddr_MoldBase_Para407, //<类型：系统；名字：；结构：MOTOR_PARA；地址：motor_addr；
        ICAddr_MoldBase_Para408, //<类型：预留；
        ICAddr_MoldBase_Para409, //<类型：预留；

        ICAddr_MoldBase_Para410, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para411, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para412, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para413, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para414, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para415, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para416, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para417, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para418, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para419, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para420, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para421, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para422, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para423, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para424, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para425, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para426, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para427, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para428, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para429, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para430, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para431, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para432, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para433, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para434, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para435, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para436, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para437, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para438, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para439, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para440, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para441, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para442, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para443, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para444, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para445, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para446, //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para447, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para448, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para449, //<类型：系统；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
        ICAddr_MoldBase_Para450, //<类型：预留；
        ICAddr_MoldBase_Para451, //<类型：预留；
        ICAddr_MoldBase_Para452, //<类型：预留；
        ICAddr_MoldBase_Para453, //<类型：预留；
        ICAddr_MoldBase_Para454, //<类型：预留；
        ICAddr_MoldBase_Para455, //<类型：预留；
        ICAddr_MoldBase_Para456, //<类型：预留；
        ICAddr_MoldBase_Para457, //<类型：预留；
        ICAddr_MoldBase_Para458, //<类型：预留；
        ICAddr_MoldBase_Para459, //<类型：预留；
        ICAddr_MoldBase_Para460, //<类型：预留；
        ICAddr_MoldBase_Para461, //<类型：预留；
        ICAddr_MoldBase_Para462, //<类型：预留；
        ICAddr_MoldBase_Para463, //<类型：预留；
        ICAddr_MoldBase_Para464, //<类型：预留；
        ICAddr_MoldBase_Para465, //<类型：预留；
        ICAddr_MoldBase_Para466, //<类型：预留；
        ICAddr_MoldBase_Para467, //<类型：预留；
        ICAddr_MoldBase_Para468, //<类型：预留；
        ICAddr_MoldBase_Para469, //<类型：预留；
        ICAddr_MoldBase_Para470, //<类型：预留；
        ICAddr_MoldBase_Para471, //<类型：预留；
        ICAddr_MoldBase_Para472, //<类型：预留；
        ICAddr_MoldBase_Para473, //<类型：预留；
        ICAddr_MoldBase_Para474, //<类型：预留；
        ICAddr_MoldBase_Para475, //<类型：预留；
        ICAddr_MoldBase_Para476, //<类型：预留；
        ICAddr_MoldBase_Para477, //<类型：预留；
        ICAddr_MoldBase_Para478, //<类型：预留；
        ICAddr_MoldBase_Para479, //<类型：预留；
        ICAddr_MoldBase_Para480, //<类型：预留；
        ICAddr_MoldBase_Para481, //<类型：预留；
        ICAddr_MoldBase_Para482, //<类型：预留；
        ICAddr_MoldBase_Para483, //<类型：预留；
        ICAddr_MoldBase_Para484, //<类型：预留；
        ICAddr_MoldBase_Para485, //<类型：预留；
        ICAddr_MoldBase_Para486, //<类型：预留；
        ICAddr_MoldBase_Para487, //<类型：预留；
        ICAddr_MoldBase_Para488, //<类型：预留；
        ICAddr_MoldBase_Para489, //<类型：预留；
        ICAddr_MoldBase_Para490, //<类型：预留；
        ICAddr_MoldBase_Para491, //<类型：预留；
        ICAddr_MoldBase_Para492, //<类型：预留；
        ICAddr_MoldBase_Para493, //<类型：预留；
        ICAddr_MoldBase_Para494, //<类型：预留；
        ICAddr_MoldBase_Para495, //<类型：预留；
        ICAddr_MoldBase_Para496, //<类型：预留；
        ICAddr_MoldBase_Para497, //<类型：预留；
        ICAddr_MoldBase_Para498, //<类型：预留；
        ICAddr_MoldBase_Para499, //<类型：预留；
        /*****************************************************************/
        ICAddr_Adjustment_Para500, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para501, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para502, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para503, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para504, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para505, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para506, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para507, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para508, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para509, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para510, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para511, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para512, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para513, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para514, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para515, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para516, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para517, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para518, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para519, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para520, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para521, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para522, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para523, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para524, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para525, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para526, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para527, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para528, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para529, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para530, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para531, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para532, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para533, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para534, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para535, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para536, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para537, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para538, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para539, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para540, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para541, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para542, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para543, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para544, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para545, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para546, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para547, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para548, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para549, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para550, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para551, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para552, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para553, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para554, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para555, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para556, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para557, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para558, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para559, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para560, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para561, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para562, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para563, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para564, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para565, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para566, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para567, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para568, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para569, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para570, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para571, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para572, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para573, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para574, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para575, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para576, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para577, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para578, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para579, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para580, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para581, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para582, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para583, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para584, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para585, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para586, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para587, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para588, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para589, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para590, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para591, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para592, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para593, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para594, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para595, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para596, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para597, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para598, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para599, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para600, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para601, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para602, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para603, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para604, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para605, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para606, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para607, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para608, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para609, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para610, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para611, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para612, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para613, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para614, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para615, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para616, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para617, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para618, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para619, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para620, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para621, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para622, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para623, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para624, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para625, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para626, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para627, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para628, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para629, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para630, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para631, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para632, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para633, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para634, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para635, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para636, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para637, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para638, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para639, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para640, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para641, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para642, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para643, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para644, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para645, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para646, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para647, //<类型：模号；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para648, //<类型：模号；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para649, //<类型：模号；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para650, //<类型：模号；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para651, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para652, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para653, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para654, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para655, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para656, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para657, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para658, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para659, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para660, //<类型：系统；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
        ICAddr_Adjustment_Para661, //<类型：预留；
        ICAddr_Adjustment_Para662, //<类型：预留；
        ICAddr_Adjustment_Para663, //<类型：预留；
        ICAddr_Adjustment_Para664, //<类型：预留；
        ICAddr_Adjustment_Para665, //<类型：预留；
        ICAddr_Adjustment_Para666, //<类型：预留；
        ICAddr_Adjustment_Para667, //<类型：预留；
        ICAddr_Adjustment_Para668, //<类型：预留；
        ICAddr_Adjustment_Para669, //<类型：预留；
        ICAddr_Adjustment_Para670, //<类型：预留；
        ICAddr_Adjustment_Para671, //<类型：预留；
        ICAddr_Adjustment_Para672, //<类型：预留；
        ICAddr_Adjustment_Para673, //<类型：预留；
        ICAddr_Adjustment_Para674, //<类型：预留；
        ICAddr_Adjustment_Para675, //<类型：预留；
        ICAddr_Adjustment_Para676, //<类型：预留；
        ICAddr_Adjustment_Para677, //<类型：预留；
        ICAddr_Adjustment_Para678, //<类型：预留；
        ICAddr_Adjustment_Para679, //<类型：预留；
        ICAddr_Adjustment_Para680, //<类型：预留；
        ICAddr_Adjustment_Para681, //<类型：预留；
        ICAddr_Adjustment_Para682, //<类型：预留；
        ICAddr_Adjustment_Para683, //<类型：预留；
        ICAddr_Adjustment_Para684, //<类型：预留；
        ICAddr_Adjustment_Para685, //<类型：预留；
        ICAddr_Adjustment_Para686, //<类型：预留；
        ICAddr_Adjustment_Para687, //<类型：预留；
        ICAddr_Adjustment_Para688, //<类型：预留；
        ICAddr_Adjustment_Para689, //<类型：预留；
        ICAddr_Adjustment_Para690, //<类型：预留；
        ICAddr_Adjustment_Para691, //<类型：预留；
        ICAddr_Adjustment_Para692, //<类型：预留；
        ICAddr_Adjustment_Para693, //<类型：预留；
        ICAddr_Adjustment_Para694, //<类型：预留；
        ICAddr_Adjustment_Para695, //<类型：预留；
        ICAddr_Adjustment_Para696, //<类型：预留；
        ICAddr_Adjustment_Para697, //<类型：预留；
        ICAddr_Adjustment_Para698, //<类型：预留；
        ICAddr_Adjustment_Para699, //<类型：预留；
        ICAddr_Adjustment_Para700, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para701, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para702, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para703, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para704, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para705, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para706, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para707, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para708, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para709, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para710, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para711, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para712, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para713, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para714, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para715, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para716, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para717, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para718, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para719, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para720, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para721, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para722, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para723, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para724, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para725, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para726, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para727, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para728, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para729, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para730, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para731, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para732, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para733, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para734, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para735, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para736, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para737, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para738, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para739, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para740, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para741, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para742, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para743, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para744, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para745, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para746, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para747, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para748, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para749, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para750, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para751, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para752, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para753, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para754, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para755, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para756, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para757, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para758, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para759, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para760, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para761, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para762, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para763, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para764, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para765, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para766, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para767, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para768, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para769, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para770, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para771, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para772, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para773, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para774, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para775, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para776, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para777, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para778, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para779, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para780, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para781, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para782, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para783, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para784, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para785, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para786, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para787, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para788, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para789, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para790, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para791, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para792, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para793, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para794, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para795, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para796, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para797, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para798, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para799, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para800, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para801, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para802, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para803, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para804, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para805, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para806, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para807, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para808, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para809, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para810, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para811, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para812, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para813, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para814, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para815, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para816, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para817, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para818, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para819, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para820, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para821, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para822, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para823, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para824, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para825, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para826, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para827, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para828, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para829, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para830, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para831, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para832, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para833, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para834, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para835, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para836, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para837, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para838, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para839, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para840, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para841, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para842, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para843, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para844, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para845, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para846, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para847, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para848, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para849, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para850, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para851, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para852, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para853, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para854, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para855, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para856, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para857, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para858, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para859, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para860, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para861, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para862, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para863, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para864, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para865, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para866, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para867, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para868, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para869, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para870, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para871, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para872, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para873, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para874, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para875, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para876, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para877, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para878, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para879, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para880, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para881, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para882, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para883, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para884, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para885, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para886, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para887, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para888, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para889, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para890, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para891, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para892, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para893, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para894, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para895, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para896, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para897, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para898, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para899, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para900, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para901, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para902, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para903, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para904, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para905, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para906, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para907, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para908, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para909, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para910, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para911, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para912, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para913, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para914, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para915, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para916, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para917, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para918, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para919, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para920, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para921, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para922, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para923, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para924, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para925, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para926, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para927, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para928, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para929, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para930, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para931, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para932, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para933, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para934, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para935, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para936, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para937, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para938, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para939, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para940, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para941, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para942, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para943, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para944, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para945, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para946, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para947, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para948, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para949, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para950, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para951, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para952, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para953, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para954, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para955, //<类型：系统；名字：；结构：ALARM_PARA；地址：alarm_addr；
        ICAddr_Adjustment_Para956, //<类型：预留；
        ICAddr_Adjustment_Para957, //<类型：预留；
        ICAddr_Adjustment_Para958, //<类型：预留；
        ICAddr_Adjustment_Para959, //<类型：预留；
        ICAddr_Adjustment_Para960, //<类型：预留；
        ICAddr_Adjustment_Para961, //<类型：预留；
        ICAddr_Adjustment_Para962, //<类型：预留；
        ICAddr_Adjustment_Para963, //<类型：预留；
        ICAddr_Adjustment_Para964, //<类型：预留；
        ICAddr_Adjustment_Para965, //<类型：预留；
        ICAddr_Adjustment_Para966, //<类型：预留；
        ICAddr_Adjustment_Para967, //<类型：预留；
        ICAddr_Adjustment_Para968, //<类型：预留；
        ICAddr_Adjustment_Para969, //<类型：预留；
        ICAddr_Adjustment_Para970, //<类型：预留；
        ICAddr_Adjustment_Para971, //<类型：预留；
        ICAddr_Adjustment_Para972, //<类型：预留；
        ICAddr_Adjustment_Para973, //<类型：预留；
        ICAddr_Adjustment_Para974, //<类型：预留；
        ICAddr_Adjustment_Para975, //<类型：预留；
        ICAddr_Adjustment_Para976, //<类型：预留；
        ICAddr_Adjustment_Para977, //<类型：预留；
        ICAddr_Adjustment_Para978, //<类型：预留；
        ICAddr_Adjustment_Para979, //<类型：预留；
        ICAddr_Adjustment_Para980, //<类型：预留；
        ICAddr_Adjustment_Para981, //<类型：预留；
        ICAddr_Adjustment_Para982, //<类型：预留；
        ICAddr_Adjustment_Para983, //<类型：预留；
        ICAddr_Adjustment_Para984, //<类型：预留；
        ICAddr_Adjustment_Para985, //<类型：预留；
        ICAddr_Adjustment_Para986, //<类型：预留；
        ICAddr_Adjustment_Para987, //<类型：预留；
        ICAddr_Adjustment_Para988, //<类型：预留；
        ICAddr_Adjustment_Para989, //<类型：预留；
        ICAddr_Adjustment_Para990, //<类型：预留；
        ICAddr_Adjustment_Para991, //<类型：预留；
        ICAddr_Adjustment_Para992, //<类型：预留；
        ICAddr_Adjustment_Para993, //<类型：预留；
        ICAddr_Adjustment_Para994, //<类型：预留；
        ICAddr_Adjustment_Para995, //<类型：预留；
        ICAddr_Adjustment_Para996, //<类型：预留；
        ICAddr_Adjustment_Para997, //<类型：预留；
        ICAddr_Adjustment_Para998, //<类型：预留；
        ICAddr_Adjustment_Para999, //<类型：预留；
        ICAddr_CanOpen_Para1000,
        ICAddr_CanOpen_Para1350 = 1400,
        ICAddr_HeatTimer_Para1 = 1436, //<类型：模号；名字：周日；结构：HEAT_TIMER；地址：heat_addr;
        ICAddr_HeatTimer_Para2, //<类型：模号；名字：周一；结构：HEAT_TIMER；地址：heat_addr;
        ICAddr_HeatTimer_Para3, //<类型：模号；名字：周二；结构：HEAT_TIMER；地址：heat_addr;
        ICAddr_HeatTimer_Para4, //<类型：模号；名字：周三；结构：HEAT_TIMER；地址：heat_addr;
        ICAddr_HeatTimer_Para5, //<类型：模号；名字：周四；结构：HEAT_TIMER；地址：heat_addr;
        ICAddr_HeatTimer_Para6, //<类型：模号；名字：周五；结构：HEAT_TIMER；地址：heat_addr;
        ICAddr_HeatTimer_Para7, //<类型：模号；名字：周六；结构：HEAT_TIMER；地址：heat_addr;
        ICAddr_HeatTimer_Para8, //<类型：系统；名字：安全标准；结构：SAFETY_STANDARDS；地址：safe_addr;

        ICAddr_Write_Section_End = 1536, //<可写参数地址段结束哨兵

        ICAddr_Read_Status0, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status1, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status2, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status3, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status4, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status5, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status6, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status7, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status8, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status9, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status10, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status11, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status12, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status13, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status14, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status15, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status16, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status17, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status18, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status19, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status20, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status21, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status22, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status23, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status24, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status25, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status26, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status27, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status28, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status29, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status30, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status31, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status32, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status33, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status34, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status35, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status36, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status37, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status38, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status39, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status40, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status41, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status42, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status43, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status44, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status45, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status46, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status47, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status48, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status49, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status50, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status51, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status52, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status53, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status54, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status55, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status56, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status57, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status58, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status59, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status60, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status61, //<类型：系统；名字：；结构：READ_PARA；地址：read_addr；
        ICAddr_Read_Status62, //<类型：预留；
                

        ICAddr_Read_Section_End, //<
        ICAddr_ErrAddr, //<错误帧用的地址
        ICAddr_NIL //<参数地址结束哨兵
    } ICAddr;

    /*! \brief 动作枚举*/
    typedef enum {
        ACTION_NULL, //< 无动作
        ACTION_MANUAL, //< 手动模式
        ACTION_SEMI_AUTO, //< 半自动模式
        ACTION_AUTO, //< 全自动模式
        ACTION_HEAT, // 加热
        ACTION_MOTOR_RUN, // 马达
        ACTION_AUTO_RUN, // 全自动运行
        ACTION_MANUAL_LUBRICATE, // 手动润滑
        ACTION_MOLD_CLOSE, //< 关模动作
        ACTION_NOZZLE_ADV, //< 座进动作
        ACTION_NOZZLE_RET, //< 座退动作
        ACTION_INJECT_IN, //< 射进动作
        ACTION_INJECT_BACK, //< 射退动作
        ACTION_CHARGE, //< 加料动作
        ACTION_AUTO_PURGE, //< 清料动作
        ACTION_CORE1_IN, //< 抽芯A入动作
        ACTION_CORE1_OUT, //< 抽芯A出动作
        ACTION_CORE2_IN, //< 抽芯B入动作
        ACTION_CORE2_OUT, //< 抽芯B出动作
        ACTION_CORE3_IN, //< 抽芯C入动作
        ACTION_CORE3_OUT, //< 抽芯C出动作
        ACTION_CORE4_IN, //< 抽芯D入动作
        ACTION_CORE4_OUT, //< 抽芯D出动作
        ACTION_MOLD_OPEN, //< 开模动作
        ACTION_EJECT_ADV, //< 顶进动作
        ACTION_EJECT_RET, //< 顶退动作
        ACTION_MOLD_THICKNESS, //< 调模使用
        ACTION_MOLD_THIN, //< 调模进
        ACTION_MOLD_THICK, //< 调模退
        ACTION_AUTO_MOLD_ADJ, //< 自动调模
        ACTION_AIR_EJECT_MOV, //< 公模吹气
        ACTION_AIR_EJECT_STN, //< 母模吹气
        ACTION_PRODUCTCLEAR, //< 计数清零
        ACTION_BADPRODUCTCLEAR, //< 劣品清零
        ACTION_MOLDCLEAR, //< 模数归零
        ACTION_CONFIRMATION_ALARM, //< 警报确认

        ACTION_READ_MOLD_CLOSE1, //< 关模1段32
        ACTION_READ_MOLD_CLOSE2, //< 关模2段33
        ACTION_READ_MOLD_CLOSE3, //< 关模3段34
        ACTION_READ_MOLD_CLOSE4, //< 关模4段32
        ACTION_READ_MOLD_CLOSE5, //< 关模5段32
        ACTION_READ_MOLD_CLOSE6, //< 关模6段32
        ACTION_READ_MOLD_CLOSE7, //< 关模7段32
        ACTION_READ_MOLD_CLOSE8, //< 关模8段32
        ACTION_READ_MOLD_CLOSE9, //< 低压锁模36
        ACTION_READ_MOLD_CLOSE10, //< 高压锁模36
        ACTION_READ_MOLD_OPEN1, //< 开模1段37
        ACTION_READ_MOLD_OPEN2, //< 开模2段38
        ACTION_READ_MOLD_OPEN3, //< 开模3段39
        ACTION_READ_MOLD_OPEN4, //< 开模4段40
        ACTION_READ_MOLD_OPEN5, //< 开模5段41
        ACTION_READ_MOLD_OPEN6, //< 开模6段41
        ACTION_READ_MOLD_OPEN7, //< 开模7段41
        ACTION_READ_MOLD_OPEN8, //< 开模8段41
        ACTION_READ_MOLD_OPEN9, //< 开模9段41
        ACTION_READ_MOLD_OPEN10, //< 开模10段41
        ACTION_READ_INJECT_IN1, //< 射进1段动作42
        ACTION_READ_INJECT_IN2, //< 射进2段动作43
        ACTION_READ_INJECT_IN3, //< 射进3段动作44
        ACTION_READ_INJECT_IN4, //< 射进4段动作45
        ACTION_READ_INJECT_IN5, //< 射进5段动作46
        ACTION_READ_INJECT_IN6, //< 射进6段动作47
        ACTION_READ_INJECT_IN7, //< 射进7段动作47
        ACTION_READ_INJECT_IN8, //< 射进8段动作47
        ACTION_READ_INJECT_IN9, //< 射进9段动作47
        ACTION_READ_INJECT_IN10, //< 射进10段动作47
        ACTION_READ_BEFORE_SUCKBACK, //< 前松退48
        ACTION_READ_AFTER_SUCKBACK, //< 后松退动作49
        ACTION_READ_KEEPPRESS1, //< 保压1段50
        ACTION_READ_KEEPPRESS2, //< 保压2段51
        ACTION_READ_KEEPPRESS3, //< 保压3段52
        ACTION_READ_KEEPPRESS4, //< 保压4段53
        ACTION_READ_KEEPPRESS5, //< 保压5段54
        ACTION_READ_KEEPPRESS6, //< 保压6段54
        ACTION_READ_KEEPPRESS7, //< 保压7段54
        ACTION_READ_KEEPPRESS8, //< 保压8段54
        ACTION_READ_KEEPPRESS9, //< 保压9段54
        ACTION_READ_KEEPPRESS10, //< 保压10段54
        ACTION_READ_COOLING, //<	冷却55
        ACTION_READ_NOZZLE_ADV, //<	座进56
        ACTION_READ_NOZZLE_FAST_ADV, //< 座进快速57
        ACTION_READ_NOZZLE_SLOW_ADV, //< 座进慢速58
        ACTION_READ_NOZZLE_RET, //<	座退59
        ACTION_READ_EJECT_ADV1, //<	顶进一段60
        ACTION_READ_EJECT_ADV2, //<	顶进二段61
        ACTION_READ_EJECT_RET1, //<	顶退一段62
        ACTION_READ_EJECT_RET2, //<	顶退二段63
        ACTION_READ_CHARGE, //< 加料
        ACTION_READ_CHARGE1, //< 加料一段
        ACTION_READ_CHARGE2, //< 加料二段
        ACTION_READ_CHARGE3, //< 加料三段
        ACTION_READ_CHARGE4, //< 加料四段
        ACTION_READ_CORE1IN, //< 抽芯A入
        ACTION_READ_CORE2IN, //< 抽芯B入
        ACTION_READ_TEETH1IN, //< 绞牙A入
        ACTION_READ_TEETH2IN, //< 绞牙B入
        ACTION_READ_CORE3IN, //< 抽芯C入
        ACTION_READ_CORE4IN, //< 抽芯D入
        ACTION_READ_CORE1OUT, //< 抽芯A出
        ACTION_READ_CORE2OUT, //< 抽芯B出
        ACTION_READ_TEETH1OUT, //< 绞牙A出
        ACTION_READ_TEETH2OUT, //< 绞牙B出
        ACTION_READ_CORE3OUT, //< 抽芯C出
        ACTION_READ_CORE4OUT, //< 抽芯D出
        ACTION_READ_MOLDTHIN, //< 调模进
        ACTION_READ_MOLDTHICK, //< 调模退
        ACTION_READ_AIR_BLST_MOV, //< 动模吹气
        ACTION_READ_AIR_BLST_STN, //< 静模吹气
        ACTION_READ_INJECT_BACK1, //< 射一
        ACTION_READ_INJECT_BACK2, //< 射二
        ACTION_READ_BEFOREINJECTCHARGE, //< 射前加料中
        ACTION_READ_AIR_BLST_MOV1, //< 动模吹气1
        ACTION_READ_AIR_BLST_MOV2, //< 动模吹气2
        ACTION_READ_AIR_BLST_MOV3, //< 动模吹气3
        ACTION_READ_AIR_BLST_STN1, //< 静模吹气1
        ACTION_READ_AIR_BLST_STN2, //< 静模吹气2
        ACTION_READ_AIR_BLST_STN3, //< 静模吹气3
        ACTION_READ_PRESSANDSPEEDTESTING, //< 压力/流量比例阀测试中
        ACTION_READ_DELAY, //< 延迟中
        ACTION_READ_SUCKBACK,//< 松退
        ACTION_READ_TEETH3IN, //< 绞牙C入
        ACTION_READ_TEETH4IN, //< 绞牙D入
        ACTION_READ_TEETH3OUT, //< 绞牙C出
        ACTION_READ_TEETH4OUT, //< 绞牙D出
        ACTION_READ_WAIT_FOR_CLOSE, //< 等待关模允许
        ACTION_READ_WAIT_FOR_EJECT, //< 等待顶进允许
        ACTION_READ_WAIT_FOR_OPEN, //< 等待开模允许
        ACTION_READ_PRE_INJECT, //< 预射胶中
        /**********************************************/
        ACTION_WAITING = 2048, //< 动作等待中（双油路中使用）

    } ICACTTION;

    /*! \brief 模式状态枚举*/
    typedef enum {
        STATUS_MANUAL, //< 手动模式
        STATUS_SEMI_AUTO, //< 半自动模式
        STATUS_AUTO //< 全自动模式
    } ICSTATUS;


#define AUTO_RUNNING_STATUS                 0x01u        //< 自动运行状态
#define MOLD_THICKNESS_STATUS               0x02u      //< 调模使用状态
#define AUTO_AUTO_MOLD_ADJ_STATUS           0x04u  //< 自动调模状态
#define MOTOR_STATUS                        0x08u  //< 马达状态
#define FORCELUBRICATE_STATUS               0x10u  //< 润滑状态

    typedef union {

        struct {
            uint32_t auto_run : 1; //< 自动运行状态
            uint32_t mold_thickness : 1; //< 调模使用状态
            uint32_t auto_mold_adj : 1; //< 自动调模状态
            uint32_t motor : 1; //< 马达状态
            uint32_t lubricate : 1; //< 润滑状态
        };
        uint32_t all;
    } MACHINE_STATUS;

    /*! \brief 调试地址*/
    typedef enum {
        DEBUG_NULL,
        DEBUG_CPUUSAGE, //< CPU使用率
        DEBUG_DA_CPUUSAGE, //< DA任务CPU使用率
        DEBUG_DA_STK_SIZE, //< DA任务堆栈大小
        DEBUG_DA_STK_USE, //< DA任务堆栈实际使用大小
        DEBUG_DA_SCHEDLOCKTIMEMAX, //< DA任务堆栈空余大小
        DEBUG_DA_CYCLES_DELAY, //< DA任务执行时间
        DEBUG_DA_TICK_REMAIN, //< DA任务到达剩余时间
        DEBUG_DA_TASK_STATE, //< DA任务状态

        DEBUG_IO_CPUUSAGE, //<IO任务CPU使用率
        DEBUG_IO_STK_SIZE, //< IO任务堆栈大小
        DEBUG_IO_STK_USE, //< IO任务堆栈实际使用大小
        DEBUG_IO_SCHEDLOCKTIMEMAX, //< IO任务堆栈空余大小
        DEBUG_IO_CYCLES_DELAY, //< IO任务执行时间
        DEBUG_IO_TICK_REMAIN, //< IO任务到达剩余时间
        DEBUG_IO_TASK_STATE, //< IO任务状态

        DEBUG_RU_CPUUSAGE, //< 电子尺任务CPU使用率
        DEBUG_RU_STK_SIZE, //< 电子尺任务堆栈大小
        DEBUG_RU_STK_USE, //< 电子尺任务堆栈实际使用大小
        DEBUG_RU_SCHEDLOCKTIMEMAX, //< 电子尺任务堆栈空余大小
        DEBUG_RU_CYCLES_DELAY, //< 电子尺任务执行时间
        DEBUG_RU_TICK_REMAIN, //< 电子尺任务到达剩余时间
        DEBUG_RU_TASK_STATE, //< 电子尺任务状态

        DEBUG_TEMP_CPUUSAGE, //< 温度任务CPU使用率
        DEBUG_TEMP_STK_SIZE, //< 温度任务堆栈大小
        DEBUG_TEMP_STK_USE, //< 温度任务堆栈实际使用大小
        DEBUG_TEMP_SCHEDLOCKTIMEMAX, //< 温度任务堆栈空余大小
        DEBUG_TEMP_CYCLES_DELAY, //< 温度任务执行时间
        DEBUG_TEMP_TICK_REMAIN, //< 温度任务到达剩余时间
        DEBUG_TEMP_TASK_STATE, //< 温度任务状态

        DEBUG_LOGIC_CPUUSAGE, //< 逻辑任务CPU使用率
        DEBUG_LOGIC_STK_SIZE, //< 逻辑任务堆栈大小
        DEBUG_LOGIC_STK_USE, //< 逻辑任务堆栈实际使用大小
        DEBUG_LOGIC_SCHEDLOCKTIMEMAX, //< 逻辑任务堆栈空余大小
        DEBUG_LOGIC_CYCLES_DELAY, //< 逻辑任务执行时间
        DEBUG_LOGIC_TICK_REMAIN, //< 逻辑任务到达剩余时间
        DEBUG_LOGIC_TASK_STATE, //< 逻辑任务状态

        DEBUG_ACTION_CPUUSAGE, //< 动作处理任务CPU使用率
        DEBUG_ACTION_STK_SIZE, //< 动作处理任务堆栈大小
        DEBUG_ACTION_STK_USE, //< 动作处理任务堆栈实际使用大小
        DEBUG_ACTION_SCHEDLOCKTIMEMAX, //< 动作处理任务堆栈空余大小
        DEBUG_ACTION_CYCLES_DELAY, //< 动作处理任务执行时间
        DEBUG_ACTION_TICK_REMAIN, //< 动作处理任务到达剩余时间
        DEBUG_ACTION_TASK_STATE, //< 动作处理任务状态

        DEBUG_COMMUNICATION_CPUUSAGE, //< 通讯任务CPU使用率
        DEBUG_COMMUNICATION_STK_SIZE, //< 通讯任务堆栈大小
        DEBUG_COMMUNICATION_STK_USE, //< 通讯任务堆栈实际使用大小
        DEBUG_COMMUNICATION_SCHEDLOCKTIMEMAX, //< 通讯任务堆栈空余大小
        DEBUG_COMMUNICATION_CYCLES_DELAY, //< 通讯任务执行时间
        DEBUG_COMMUNICATION_TICK_REMAIN, //< 通讯任务到达剩余时间
        DEBUG_COMMUNICATION_TASK_STATE, //< 通讯任务状态

        BEBUG_ADDR_END, //<


    } DEBUG_ADDR;

    typedef enum _ALARM_ADDR {
        // 报警0等级，提示作用，不闪灯，不发声
        ALARM_NULL = 0,
        ALARM_MACHINE_ADJUST, //<名字：机械调整中
        ALARM_MOTOR_RUNING, //<名字：马达启动中
        ALARM_AUTO_PURGING, //<名字：自动清料中
        ALARM_IO_TURNING, //<名字：IO转向中
        ALARM_IO_SIMULATING, //<名字：IO模拟中
        ALARM_NEXTMOLDSTOP, //<名字：下一模停机
        ALARM_KEEP_WARM_STATE, //<名字：保温状态中
        ALARM_PLEASE_OPEN_SAVEDOOR, //<名字：请开安全门
        ALARM_PLEASE_CLOSE_SAVEDOOR, //<名字：请关安全门
        ALARM_PLEASE_PRESS_AUTO_RUN, //<名字：请按运行键
        ALARM_COMMUNICATION_ANOMALY, //<名字：通讯异常
        ALARM_CORE1_IN_NOT_USE, //<名字：抽芯A入未使用
        ALARM_CORE2_IN_NOT_USE, //<名字：抽芯B入未使用
        ALARM_CORE3_IN_NOT_USE, //<名字：抽芯C入未使用
        ALARM_CORE4_IN_NOT_USE, //<名字：抽芯D入未使用
        ALARM_CORE1_OUT_NOT_USE, //<名字：抽芯A出未使用
        ALARM_CORE2_OUT_NOT_USE, //<名字：抽芯B出未使用
        ALARM_CORE3_OUT_NOT_USE, //<名字：抽芯C出未使用
        ALARM_CORE4_OUT_NOT_USE, //<名字：抽芯D出未使用
        ALARM_EJECT_NOT_CHOOSE, //<名字：顶针未使用
        ALARM_AIR_EJECT_M_NOT_USE, //<名字：动模吹气未使用
        ALARM_AIR_EJECT_F_NOT_USE, //<名字：静模吹气未使用
        ALARM_PLEASE_HEATER, //<名字：请加热
        ALARM_MOLD_PLACE_ERR, //<名字：动模位置器故障
        ALARM_INJECT_PLACE_ERR, //<名字：射出位置器故障
        ALARM_NOZZLE_PLACE_ERR, //<名字：射座位置器故障
        ALARM_EJECT_PLACE_ERR, //<名字：顶针位置器故障
        ALARM_MOTOR_NOTRUN, //<名字：马达未启动
        ALARM_EJECT_RET_NOT_ARRIVAL, //<名字：顶退未到位
        ALARM_MOLD_OPEN_NOT_IN_PLACE, //<名字：开模未到位
        ALARM_WAIT_NEXT_SEMIAUTORUN, //<名字：请开安全门，等待下一次半自动启动
        ALARM_AUTO_PURGE_DONE, //<名字：自动清料完成
        ALARM_INJECTIONSHIELD_OPEN, //<名字：射出防护罩
        ALARM_TEMPERATURE_CONVERT_FALSE, //<名字：温度采集失败
        ALARM_MOLD_HIGHPRESS_ERR, //<名字：高压锁模位置错误
        ALARM_FRONTDOOR_OPEN, //<名字：前安全门开
        ALARM_MOTORSTARTPROTECTTIMEUP, //<名字：马达启动保护时间到
        ALARM_NOZZLEADV_PROTECT_TIME, //<名字：座进保护时间到
        ALARM_SYSTEM_PRESS_SET_ERR, //<名字：系统压最大值设置错误
        ALARM_SYSTEM_SPEED_SET_ERR, //<名字：流量最大值设置错误
        ALARM_SYSTEM_BACKPRESS_SET_ERR, //<名字：背压最大值设置错误
        ALARM_TELEDIPGAUGE_ERR, //<名字：电子尺长度设置错误
        ALARM_OILCANJOURNEY_AD_VALUE_ERR, //<名字：油缸最大、最小AD值设置错误
        ALARM_MOLD_THIN_LIMIT, //<名字：达到调模进极限
        ALARM_MOLD_THICK_LIMIT, //<名字：达到调模退极限
        ALARM_MOLD_THICKNESS_DONE, //<名字：自动调模完成
        ALARM_SCREW_PROTECT, //<名字：镙杆保护
        ALARM_NOT_REACH_NORMAL_TEMPRATURE, //<名字：料温未到正常温度
        ALARM_EMERGENCY_STOP, //<名字：紧急停止
        ALARM_TAKEOUT_NOPRODUCT,
        ALARM_SAVE_RELAY_ERR,
        ALARM_PLEASE_RESET,
        ALARM_STORING_PRESS,
        ALARM_SPECIALCOREALLOW,
        ALARM_POORPRODUCT_SERIES,
        ALARM_NOZZLE_NOTLOCATE,
        ALARM_AUTO_ADJUST_PLACE,
        ALARM_IO_OUT_ERR,
        ALARM_MOLD_ADJUST_LIMIT,
        ALARM_TAKEOUT_WARM, //
        ALARM_ELECTRIC_EYE_PROTECT, //<名字：电眼保护时间到
        ALARM_ELECTRIC_EYE_SHUTOUT, //<名字：电眼遮住时间过长
        ALARM_MOLDCLOSE_POS_ERR, //<名字：关模位置参数设定错误
        ALARM_MOLDCLOSE_P_ERR, //<名字：关模压力参数设定错误
        ALARM_MOLDCLOSE_S_ERR, //<名字：关模流量参数设定错误
        ALARM_MOLDOPEN_POS_ERR, //<名字：开模位置参数设定错误
        ALARM_MOLDOPEN_P_ERR, //<名字：开模压力参数设定错误
        ALARM_MOLDOPEN_S_ERR, //<名字：开模流量参数设定错误
        ALARM_INJECT_POS_ERR, //<名字：射出位置参数设定错误
        ALARM_INJECT_P_ERR, //<名字：射出压力参数设定错误
        ALARM_INJECT_S_ERR, //<名字：射出流量参数设定错误
        ALARM_NOZZLE_POS_ERR, //<名字：座台位置参数设定错误
        ALARM_NOZZLE_P_ERR, //<名字：座台压力参数设定错误
        ALARM_NOZZLE_S_ERR, //<名字：座台流量参数设定错误
        ALARM_CHARGE_POS_ERR, //<名字：加料位置参数设定错误
        ALARM_CHARGE_P_ERR, //<名字：加料压力参数设定错误
        ALARM_CHARGE_S_ERR, //<名字：加料流量参数设定错误
        ALARM_EJECT_POS_ERR, //<名字：顶针位置参数设定错误
        ALARM_EJECT_P_ERR, //<名字：顶针压力参数设定错误
        ALARM_EJECT_S_ERR, //<名字：顶针流量参数设定错误
        ALARM_CORE_POS_ERR, //<名字：抽芯位置参数设定错误
        ALARM_CORE_P_ERR, //<名字：抽芯压力参数设定错误
        ALARM_CORE_S_ERR, //<名字：抽芯流量参数设定错误
        ALARM_AIR_POS_ERR, //<名字：吹风位置参数设定错误
        ALARM_AIR_S_ERR, //<名字：吹风流量参数设定错误
        ALARM_ADJUST_ERR, //<名字：调模参数设定错误
        ALARM_TEMPERATURE_ERR, //<名字：温度参数设定错误
        ALARM_LOW_PRODUCT_ERR, //<名字：低压保护时间参数设定错误
        ALARM_RESERVE0_ERR, //<名字：预留
        ALARM_NOT_ALOW_AUTO_ERR, //<名字：顶针停留模式不允许全自动
        ALARM_PRODUCT_TIPS, //<名字：生产提示

        ALARM_SYSTEM_NOT_INIT = 95,

        // 报警1等级，闪灯，发声，不切马达，触发报警计时器计时
        ALARM_MOLD_OPEN_OVERTIME = 96, //<名字：开模超时
        ALARM_ONE_BOX_MOLD_NUMBER, //<名字：装箱模数到
        ALARM_INJECT_ANOMALY, //<名字：射胶异常
        ALARM_PRODUCT_MAXIMUM, //<名字：达到生产总数
        ALARM_GOODPRODUCT_NUMBER, //<名字：达到良品总数
        ALARM_POORPRODUCT_MAXIMUM, //<名字：达到劣品总数
        ALARM_CHARGE_ANOMALY, //<名字：加料异常
        ALARM_LOWPRESS_PROTECT, //<名字：低压保护中
        ALARM_CYCLE_OVERLONG, //<名字：周期过长
        ALARM_BACKDOOR_OPEN, //<名字：后安全门开
        ALARM_PLASTIC_TEMPRATURE_HIGH, //<名字：料温过高
        ALARM_OILLEACHNET_DIRTY, //<名字：滤油网脏
        ALARM_LUBRICATE_OIL_LOW, //<名字：润滑油位低
        ALARM_LUBRICATE1_PRESS_NOT_ARRIVA, //<名字：润滑压力未到
        ALARM_LUBRICATE2_PRESS_NOT_ARRIVA, //
        ALARM_LUBRICATE_ANOMALY, //<名字：润滑异常
        ALARM_OIL_TEMPRATURE_60, //<名字：油温达到60度
        ALARM_OIL_TEMPRATURE_70, //<名字：油温达到70度
        ALARM_THERMOCOUPLE_INJECT_CUT_OFF, //<名字：喷嘴热电偶断线
        ALARM_THERMOCOUPLE_SEG1_CUT_OFF, //<名字：第一段热电偶断线
        ALARM_THERMOCOUPLE_SEG2_CUT_OFF, //<名字：第二段热电偶断线
        ALARM_THERMOCOUPLE_SEG3_CUT_OFF, //<名字：第三段热电偶断线
        ALARM_THERMOCOUPLE_SEG4_CUT_OFF, //<名字：第四段热电偶断线
        ALARM_THERMOCOUPLE_SEG5_CUT_OFF, //<名字：第五段热电偶断线
        ALARM_THERMOCOUPLE_SEG6_CUT_OFF, //<名字：第六段热电偶断线
        ALARM_THERMOCOUPLE_OIL_CUT_OFF, //<名字：油温热电偶断线
        ALARM_MOLD_STILL_HIGHPRESS_LOCKUP, //<名字：模具仍被高压锁住
        ALARM_OIL_TEMPRATURE_HIGH, //<名字：油温过高
        ALARM_MOTOR_OVERLOAD, //<名字：马达过载
        ALARM_PLASTIC_TEMPRATURE_LOW, //<名字：料温过低
        ALARM_SERVO_ERR, //<名字：伺服驱动器故障
        ALARM_VIOLATION_SAFE_ERR, //<名字：违反安全操作
        ALARM_SERVO1_CON_ERR, //<名字：伺服驱动器1通讯故障
        ALARM_SERVO2_CON_ERR, //<名字：伺服驱动器2通讯故障
        ALARM_SERVO3_CON_ERR, //<名字：伺服驱动器3通讯故障
        ALARM_SERVO4_CON_ERR, //<名字：伺服驱动器4通讯故障

        // 报警2等级，闪灯，发声，切马达
        ALARM_TIME_OUT = 160, //<名字：报警计时到
    } ALARM_ADDR;

    typedef enum {
        ElecPosSensor_ElecFoot,
        ElecPosSensor_Contactor
    } ElecPosSensor;

    typedef enum {
        IOSim_NoUse,
        IOSim_ForceOFF,
        IOSim_ForceON
    } IOSimState;



typedef enum _Can_Communication_Addr_
{
    CAN_NULL, //<
    CAN_FAST_ACCESS_CMD, //<命令    第4位-启动，即16，5-复位
    CAN_FAST_SET_FLOW, //<流量设置
    CAN_FAST_SET_PRESS, //<压力设置
    CAN_FAST_FLOW_RISETIME, //<流量上升时间
    CAN_FAST_FLOW_FALLTIME, //<流量下降时间
    CAN_FAST_PRESS_RISETIME, //<压力上升下降时间
    CAN_FAST_PRESS_FEEDBACK_VALUE, //<压力反馈值
    CAN_FAST_FLOW_FEEDBACK_VALUE, //<电机运行转速 （流量反馈值）

    CAN_WRITE_CTRL_MODE1, //< 压力控制模式
    CAN_WRITE_CTRL_MODE, //< 控制模式
    CAN_WRITE_RATED_POWER_000, //<电机额定功率，范围：7.5～55千瓦，最小单位0.1千瓦
    CAN_WRITE_RATED_VOLTAGE_001, //<电机额定电压，范围：0V～440V，最小单位1V
    CAN_WRITE_RATED_CURRENT_002,  //<电机额定电流，范围：17～75A，最小单位0.1A
    CAN_WRITE_RATED_FREQUENCY_003, //<电机额定频率，范围：0～最大频率，最小单位0.01Hz
    CAN_WRITE_RATED_SPEED_004, //<电机额定转速，范围：0～30000rpm，最小单位1rpm
    CAN_WRITE_DRIVER_TUNE_026, //<驱动器调谐方式选择：0：无操作，；1：静态调谐；2：动态调谐；3：调谐方式3
    CAN_WRITE_MAX_SPEED_101, //<注塑机最高转速：0～3000rpm，最小单位1rpm
    CAN_WRITE_OIL_PRESS_102, //<系统油压，范围：0～最大油压（103），最小单位：0.1
    CAN_WRITE_MAX_PRESS_103, //<最大油压，范围：0～500），最小单位：0.1
    CAN_WRITE_UNDER_TOW_118, //底流：0～500，最小：1
    CAN_WRITE_UNDER_PRESS_119, //<底压：0～500，最小：1
    CAN_WRITE_ZERO_DIRFT_120,  //<AI零点自矫正，0：无效，1：使能
    CAN_WRITE_PRESS_CTRL_MAX_SPEED_122,  //<压力控制状态输出最高转速：0～1000，最小1；
    CAN_WRITE_PRESS_CTRL_MIN_PRESS_123,  //<压力控制状态输出最低油压：0～1000，最小1；
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN1, //< 油压控制比例增益1
    CAN_WRITE_OIL_INTEGRATION_TIME1, //< 油压控制积分时间1
    CAN_WRITE_OIL_DERIVATIVE_TIME1, //< 油压控制微分时间1
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN2, //< 油压控制比例增益2
    CAN_WRITE_OIL_INTEGRATION_TIME2, //< 油压控制积分时间2
    CAN_WRITE_OIL_DERIVATIVE_TIME2, //< 油压控制微分时间2
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN3, //< 油压控制比例增益3
    CAN_WRITE_OIL_INTEGRATION_TIME3, //< 油压控制积分时间3
    CAN_WRITE_OIL_DERIVATIVE_TIME3, //< 油压控制微分时间3
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN4, //< 油压控制比例增益4
    CAN_WRITE_OIL_INTEGRATION_TIME4, //< 油压控制积分时间4
    CAN_WRITE_OIL_DERIVATIVE_TIME4, //< 油压控制微分时间4
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN5, //< 油压控制比例增益5
    CAN_WRITE_OIL_INTEGRATION_TIME5, //< 油压控制积分时间5
    CAN_WRITE_OIL_DERIVATIVE_TIME5, //< 油压控制微分时间5
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN6, //< 油压控制比例增益6
    CAN_WRITE_OIL_INTEGRATION_TIME6, //< 油压控制积分时间6
    CAN_WRITE_OIL_DERIVATIVE_TIME6, //< 油压控制微分时间6
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN7, //< 油压控制比例增益7
    CAN_WRITE_OIL_INTEGRATION_TIME7, //< 油压控制积分时间7
    CAN_WRITE_OIL_DERIVATIVE_TIME7, //< 油压控制微分时间7
    CAN_WRITE_OIL_PTOPORTIONAL_GAIN8, //< 油压控制比例增益8
    CAN_WRITE_OIL_INTEGRATION_TIME8, //< 油压控制积分时间8
    CAN_WRITE_OIL_DERIVATIVE_TIME8, //< 油压控制微分时间8

    CAN_READ_RUNNING_FREQUENCY, //< 电机运行频率
    CAN_READ_BUS_VOLTAGE, //< 母线电压
    CAN_READ_OUTPUT_VOLTAGE, //< 输出电压
    CAN_READ_OUTPUT_CURRENT, //< 输出电流
    CAN_READ_OUTPUT_FREQUENCY, //< 输出功率
    CAN_READ_OUTPUT_TORQUE, //< 输出转矩
    CAN_READ_ERIVER_TEMPERATURE, //< 驱动器温度
    CAN_READ_DI_INFOMATION, //< 端子DI信息状态
    CAN_READ_DO_INFOMATION, //< 端子DO信息状态
    CAN_READ_NODE_GUARD, //< Node  Guard报文接收次数
    CAN_READ_HEARTBEAT, //< heartbeat 报文接收次数
    CAN_READ_SYNC, //< 实时电能消耗监控
    CAN_READ_SDO, //< SDO  报文接收次数
    CAN_READ_PDO, //< PDO  报文接收次数
    CAN_READ_RESOLVER_SIFNALS, //< 旋变信号干扰程度
    CAN_READ_FAULT, //< 故障代码
    CAN_READ_MOTOR_TEMPERATURE, //< 电机温度
    CAN_READ_RUNNING_ANGLE, //< 电机实际运行角度
    CAN_READ_SETTING_PRESS, //<油压给定值
    CAN_READ_MOTOR_SPEED, //<电机转速
    CAN_READ_AI1_VOL_VALUE, //< 模拟量输入AI1电压值
    CAN_READ_AI2_VOL_VALUE, //< 模拟量输入AI2电压值
    CAN_READ_AI3_VOL_VALUE, //< 模拟量输入AI3电压值
    CAN_READ_ADDR_CHECK, //< 按地址查询
    CAN_Addr_Err, //<
    CAN_Addr_End = 400, //<
} CanAddr;

#define GetIOSimVal(index, addrVal, retVal) \
    retVal = (addrVal >> (index << 1)) & 0x03

#define SetIOSimVal(index, addrVal, ioVal) \
    addrVal &= ~(3 << (index << 1)); \
    addrVal |= (ioVal << (index << 1))

#define TEMPERATURENULL		10000	// 温度设定值空时默认值


    /******************************************************************************
     动作结构
     ******************************************************************************/
    //< 动作通用参数结构

    typedef struct {
        uint32_t pos : 17; //< 类型：模号；名字：位置；精度：2；单位：mm；
        uint32_t press : 15; //< 类型：模号；名字：压力；精度：1；单位：bar；
        /**********************/
        uint32_t speed : 10; //< 类型：模号；名字：速度；精度：1；单位：%；
        uint32_t reserve0 : 22; //< 类型：模号；名字：预留；
        /**********************/
        uint32_t pu : 10; //< 类型：系统；名字：压力上升斜率
        uint32_t pd : 10; //< 类型：系统；名字：压力下降斜率；
        uint32_t reserve1 : 12; //< 类型：系统；名字：预留；
        /**********************/
        uint32_t su : 10; //< 类型：系统；名字：速度上升斜率；
        uint32_t sd : 10; //< 类型：系统；名字：速度下降斜率；
        uint32_t reserve2 : 12; //< 类型：系统；名字：预留；
    } COMMON_PARA1;

    typedef struct {
        uint32_t befo : 16; //< 类型：模号；名字：命令前延迟；精度：2；单位：s；
        uint32_t afto : 16; //< 类型：模号；名字：命令后延迟；精度：2；单位：s；
        /**********************/
        uint32_t befp : 16; //< 类型：系统；名字：比例阀前延迟；精度：2；单位：s；
        uint32_t aftp : 16; //< 类型：系统；名字：比例阀后延迟；精度：2；单位：s；
    } COMMON_PARA2;

    typedef struct {
        uint32_t time : 17; //< 类型：模号；名字：时间；精度：3；单位：s；
        uint32_t press : 15; //< 类型：模号；名字：压力；精度：1；单位：bar；
        /**********************/
        uint32_t speed : 10; //< 类型：模号；名字：速度；精度：1；单位：%；
        uint32_t reserve0 : 22; //< 类型：模号；名字：预留；
        /**********************/
        uint32_t pu : 10; //< 类型：系统；名字：压力上升斜率
        uint32_t pd : 10; //< 类型：系统；名字：压力下降斜率；
        uint32_t reserve1 : 12; //< 类型：系统；名字：预留；
        /**********************/
        uint32_t su : 10; //< 类型：系统；名字：速度上升斜率；
        uint32_t sd : 10; //< 类型：系统；名字：速度下降斜率；
        uint32_t reserve2 : 12; //< 类型：系统；名字：预留；
    } COMMON_PARA3;

    typedef struct {
        uint32_t bp : 17; //< 类型：模号；名字：背压；精度：1；单位：bar；
        uint32_t press : 15; //< 类型：模号；名字：压力；精度：1；单位：bar；
        /**********************/
        uint32_t en : 1; //< 类型：模号；名字：射前加料使能；格式：……
        //< + 0-不使用-不使用射前加料功能……
        //< + 1-使用-在射胶之前先进行加料；
        uint32_t speed : 7; //< 类型：模号；名字：速度；精度：0；单位：%；
        uint32_t time : 16; //< 类型：模号；名字：时间；精度：2；单位：s；
        uint32_t reserve0 : 8; //< 类型：模号；名字：预留；
        /**********************/
        uint32_t pu : 10; //< 类型：系统；名字：压力上升斜率
        uint32_t pd : 10; //< 类型：系统；名字：压力下降斜率；
        uint32_t reserve1 : 12; //< 类型：系统；名字：预留；
        /**********************/
        uint32_t su : 10; //< 类型：系统；名字：速度上升斜率；
        uint32_t sd : 10; //< 类型：系统；名字：速度下降斜率；
        uint32_t reserve2 : 12; //< 类型：系统；名字：预留；
    } COMMON_PARA4;

    typedef struct {
        uint32_t pos : 17; //< 类型：模号；名字：偏移距离；精度：2；单位：mm；
        uint32_t press : 15; //< 类型：模号；名字：压力；精度：1；单位：bar；
        /**********************/
        uint32_t speed : 10; //< 类型：模号；名字：速度；精度：1；单位：%；
        uint32_t reserve0 : 22; //< 类型：模号；名字：预留；
        /**********************/
        uint32_t pu : 10; //< 类型：系统；名字：压力上升斜率
        uint32_t pd : 10; //< 类型：系统；名字：压力下降斜率；
        uint32_t reserve1 : 12; //< 类型：系统；名字：预留；
        /**********************/
        uint32_t su : 10; //< 类型：系统；名字：速度上升斜率；
        uint32_t sd : 10; //< 类型：系统；名字：速度下降斜率；
        uint32_t reserve2 : 12; //< 类型：系统；名字：预留；
    } COMMON_PARA5;

    typedef struct {
        uint32_t mode : 4; //< 类型：模号；名字：动作模式；格式：……
        //< + 0-不使用-不使用吹气功能……
        //< + 1-开模位值-开模达到设定位值时候吹气动作……
        //< + 2-射胶位置-射胶达到设定位值时候吹气动作……
        //< + 3-顶针后-开顶针动作结束时候吹气动作……
        //< + 4-关模位置-关模达到设定位值时候吹气动作；
        uint32_t reserve2 : 11; //< 类型：模号；名字：预留；
        uint32_t pos : 17; //< 类型：模号；名字：动作位置；精度：1；单位：mm；
        /**********************/
        uint32_t at : 16; //< 类型：模号；名字：动作时间；精度：2；单位：s；
        uint32_t dt : 16; //< 类型：模号；名字：延迟时间；精度：2；单位：s；
        /**********************/
    } COMMON_PARA6;

    typedef struct {
        uint32_t mode : 4; //< 类型：模号；名字：动作模式；格式：……
        //< + 0-不使用-不使用抽芯功能……
        //< + 1-限位-抽芯使用限位开关……
        //< + 2-时间-抽芯使用时间开关；
        uint32_t am : 4; //< 类型：模号；名字：动作时机；格式：……
        //< + 0-关模前-抽芯动作在关模动作开始之前……
        //< + 1-开模前-抽芯动作在开模动作开始之前……
        //< + 2-关模后-抽芯动作在关模动作结束之后……
        //< + 3-开模后-抽芯动作在开模动作结束之后……
        //< + 4-运行中-抽芯动作在模动作到抽芯设定位置之时；
        uint32_t tooth : 12; //< 类型：模号；名字：牙数；精度：0；单位：pc；
        uint32_t speed : 12; //< 类型：模号；名字：速度；精度：1；单位：%；
        /**********************/
        uint32_t press : 16; //< 类型：模号；名字：压力；精度：1；单位：bar；
        uint32_t time : 16; //< 类型：模号；名字：时间；精度：2；单位：s；
        /**********************/
        uint32_t pos : 17; //< 类型：模号；名字：动作位置；精度：2；单位：mm；
        uint32_t reserve0 : 15; //< 类型：模号；名字：预留；
        /**********************/
    } COMMON_PARA7;

    typedef struct {
        uint32_t thin_p : 16; //< 类型：模号；名字：调模进压力；精度：0；单位：bar；
        uint32_t thick_p : 16; //< 类型：模号；名字：调模退压力；精度：0；单位：bar；
        /**********************/
        uint32_t thin_s : 8; //< 类型：模号；名字：调模进速度；精度：0；单位：%；
        uint32_t thick_s : 8; //< 类型：模号；名字：调模退速度；精度：0；单位：%；
        uint32_t mold_p : 16; //< 类型：模号；名字：调开关模压力；精度：0；单位：bar；
        /**********************/
        uint32_t mold_s : 8; //< 类型：模号；名字：调开关模速度；精度：0；单位：%；
        uint32_t limit_p : 16; //< 类型：模号；名字：限压；精度：0；单位：bar；
        uint32_t limit_s : 8; //< 类型：模号；名字：限速；精度：0；单位：%；
        /**********************/
    } COMMON_PARA8;

    typedef struct {
        uint32_t pos : 17; //< 类型：模号；名字：位置；精度：1；单位：mm；
        uint32_t press : 15; //< 类型：模号；名字：压力；精度：0；单位：bar；
        /**********************/
        uint32_t speed : 16; //< 类型：模号；名字：速度；精度：0；单位：%；
        uint32_t time : 16; //< 类型：模号；名字：时间；精度：2；单位：s；
        /**********************/
    } COMMON_PARA9;

    typedef struct {
        uint32_t limit_t : 16; //< 类型：模号；名字：低压模保限时；精度：2；单位：s；
        uint32_t limit_p : 16; //< 类型：模号；名字：低压模保限压；精度：0；单位：bar；
        /**********************/
        uint32_t limit_s : 16; //< 类型：模号；名字：低压模保限速；精度：0；单位：%；
        uint32_t reserve0 : 16; //< 类型：模号；名字：预留；
    } COMMON_PARA10;

    typedef struct {
        uint32_t befo : 16; //< 类型：模号；名字：抽芯命令前延迟；精度：2；单位：s；
        uint32_t afto : 16; //< 类型：模号；名字：抽芯命令后延迟；精度：2；单位：s；
        /**********************/
        uint32_t befp0 : 16; //< 类型：系统；名字：抽芯出比例阀前延迟；精度：2；单位：s；
        uint32_t aftp0 : 16; //< 类型：系统；名字：抽芯出比例阀后延迟；精度：2；单位：s；
        /**********************/
        uint32_t befp1 : 16; //< 类型：系统；名字：抽芯入比例阀前延迟；精度：2；单位：s；
        uint32_t aftp1 : 16; //< 类型：系统；名字：抽芯入比例阀后延迟；精度：2；单位：s；
        /**********************/
        uint32_t pu0 : 10; //< 类型：系统；名字：抽芯入压力上升斜率；
        uint32_t pd0 : 10; //< 类型：系统；名字：抽芯入压力下降斜率；
        uint32_t su0 : 10; //< 类型：系统；名字：抽芯入速度上升斜率；
        uint32_t reserve0 : 2; //< 类型：系统；名字：预留；
        /**********************/
        uint32_t sd0 : 10; //< 类型：系统；名字：抽芯入速度下降斜率；
        uint32_t pu1 : 10; //< 类型：系统；名字：抽芯出压力上升斜率；
        uint32_t pd1 : 10; //< 类型：系统；名字：抽芯出压力下降斜率；
        uint32_t reserve1 : 2; //< 类型：系统；名字：预留；
        /**********************/
        uint32_t su1 : 10; //< 类型：系统；名字：抽芯出速度上升斜率；
        uint32_t sd1 : 10; //< 类型：系统；名字：抽芯出速度下降斜率；
        uint32_t reserve2 : 12; //< 类型：系统；名字：预留；
    } COMMON_PARA11;

    typedef struct {
        uint32_t pu : 10; //< 类型：系统；名字：其他压力上升斜率
        uint32_t pd : 10; //< 类型：系统；名字：其他压力下降斜率；
        uint32_t su : 10; //< 类型：系统；名字：其他速度上升斜率；
        uint32_t reserve0 : 2; //< 类型：系统；名字：预留；
        /**********************/
        uint32_t sd : 10; //< 类型：系统；名字：其他速度下降斜率；
        uint32_t reserve1 : 22; //< 类型：系统；名字：预留；
    } COMMON_PARA12;

    typedef struct {
        uint32_t tptv; //< 类型：模号；名字：生产总数目标值；
        uint32_t gptv; //< 类型：模号；名字：良品数目标值；
        uint32_t bptc; //< 类型：模号；名字：劣品数目标值；
        uint32_t mptv; //< 类型：模号；名字：装箱模数目标值；
    } COMMON_PARA13;

    typedef struct {
        uint32_t tpcv; //< 类型：模号；名字：生产总数当前值；
        uint32_t gpcv; //< 类型：模号；名字：良品数当前值；
        uint32_t bpcv; //< 类型：模号；名字：劣品数当前值；
        uint32_t mpcv; //< 类型：模号；名字：装箱模数当前值；
    } COMMON_PARA14;

    typedef struct {
        uint32_t ieqv : 16; //< 类型：模号；名字：射出终点品管值；精度：1；单位：mm；
        uint32_t ceqv : 16; //< 类型：模号；名字：加料终点品管值；精度：1；单位：mm；
        uint32_t meqv : 16; //< 类型：模号；名字：开模终点品管值；精度：1；单位：mm；
        uint32_t ctqv : 16; //< 类型：模号；名字：周期时间品管值；精度：1；单位：s；
    } COMMON_PARA15;

    typedef struct {
        uint32_t ieqt : 16; //< 类型：模号；名字：射出终点品管公差值；精度：1；单位：mm；
        uint32_t ceqt : 16; //< 类型：模号；名字：加料终点品管公差值；精度：1；单位：mm；
        uint32_t moqt : 16; //< 类型：模号；名字：开模终点品管公差值；精度：1；单位：mm；
        uint32_t ctqt : 16; //< 类型：模号；名字：周期时间品管公差值；精度：1；单位：s；
    } COMMON_PARA16;

    typedef struct {
        uint32_t t0 : 16; //< 类型：模号；名字：喷嘴加热值；精度：0；单位：°C；
        uint32_t t1 : 16; //< 类型：模号；名字：加热一段加热值；精度：0；单位：°C；
        uint32_t t2 : 16; //< 类型：模号；名字：加热二段加热值；精度：0；单位：°C；
        uint32_t t3 : 16; //< 类型：模号；名字：加热三段加热值；精度：0；单位：°C；
        uint32_t t4 : 16; //< 类型：模号；名字：加热四段加热值；精度：0；单位：°C；
        uint32_t t5 : 16; //< 类型：模号；名字：加热五段加热值；精度：0；单位：°C；
        uint32_t t6 : 16; //< 类型：模号；名字：加热六段加热值；精度：0；单位：°C；
        uint32_t t7 : 16; //< 类型：模号；名字：油温设定值；精度：0；单位：°C；
    } COMMON_PARA17;

    typedef struct {
        uint32_t t0 : 16; //< 类型：模号；名字：喷嘴保温值；精度：0；单位：°C；
        uint32_t t1 : 16; //< 类型：模号；名字：加热一段保温值；精度：0；单位：°C；
        uint32_t t2 : 16; //< 类型：模号；名字：加热二段保温值；精度：0；单位：°C；
        uint32_t t3 : 16; //< 类型：模号；名字：加热三段保温值；精度：0；单位：°C；
        uint32_t t4 : 16; //< 类型：模号；名字：加热四段保温值；精度：0；单位：°C；
        uint32_t t5 : 16; //< 类型：模号；名字：加热五段保温值；精度：0；单位：°C；
        uint32_t t6 : 16; //< 类型：模号；名字：加热六段保温值；精度：0；单位：°C；
        uint32_t reserve0 : 16; //< 类型：模号；名字：预留；
    } COMMON_PARA18;

    typedef struct {
        uint32_t t0 : 16; //< 类型：模号；名字：喷嘴上偏差；精度：0；单位：°C；
        uint32_t t1 : 16; //< 类型：模号；名字：加热一段上偏差；精度：0；单位：°C；
        uint32_t t2 : 16; //< 类型：模号；名字：加热二段上偏差；精度：0；单位：°C；
        uint32_t t3 : 16; //< 类型：模号；名字：加热三段上偏差；精度：0；单位：°C；
        uint32_t t4 : 16; //< 类型：模号；名字：加热四段上偏差；精度：0；单位：°C；
        uint32_t t5 : 16; //< 类型：模号；名字：加热五段上偏差；精度：0；单位：°C；
        uint32_t t6 : 16; //< 类型：模号；名字：加热六段上偏差；精度：0；单位：°C；
        uint32_t t7 : 16; //< 类型：模号；名字：油温上偏差；精度：0；单位：°C；
    } COMMON_PARA19;

    typedef struct {
        uint32_t t0 : 16; //< 类型：模号；名字：喷嘴下偏差；精度：0；单位：°C；
        uint32_t t1 : 16; //< 类型：模号；名字：加热一段下偏差；精度：0；单位：°C；
        uint32_t t2 : 16; //< 类型：模号；名字：加热二段下偏差；精度：0；单位：°C；
        uint32_t t3 : 16; //< 类型：模号；名字：加热三段下偏差；精度：0；单位：°C；
        uint32_t t4 : 16; //< 类型：模号；名字：加热四段下偏差；精度：0；单位：°C；
        uint32_t t5 : 16; //< 类型：模号；名字：加热五段下偏差；精度：0；单位：°C；
        uint32_t t6 : 16; //< 类型：模号；名字：加热六段下偏差；精度：0；单位：°C；
        uint32_t reserve0 : 16; //< 类型：模号；名字：预留；
    } COMMON_PARA20;

    typedef struct {
        uint32_t p0 : 16; //< 类型：系统；名字：喷嘴温度PID调整P值；
        uint32_t p1 : 16; //< 类型：系统；名字：加热一段温度PID调整P值；
        uint32_t p2 : 16; //< 类型：系统；名字：加热二段温度PID调整P值；
        uint32_t p3 : 16; //< 类型：系统；名字：加热三段温度PID调整P值；
        uint32_t p4 : 16; //< 类型：系统；名字：加热四段温度PID调整P值；
        uint32_t p5 : 16; //< 类型：系统；名字：加热五段温度PID调整P值；
        uint32_t p6 : 16; //< 类型：系统；名字：加热六段温度PID调整P值；
        uint32_t cyc : 8; //< 类型：系统；名字：温控周期；精度：0；单位：s；
        uint32_t a0 : 1; //< 类型：系统；名字：喷嘴自调功能；格式：……
        //< + 0-手动加热-喷嘴使用恒温百分比进行开环加热……
        //< + 1-自动加热-使用PID自动加热；
        uint32_t a1 : 1; //< 类型：系统；名字：加热一段自调功能；格式：……
        //< + 0-关闭自调功能-使用固定的PID参数进行温度控制……
        //< + 1-打开自调功能-使用自动调整的PID参数进行温度控制；
        uint32_t a2 : 1; //< 类型：系统；名字：加热二段自调功能；格式：……
        //< + 0-关闭自调功能-使用固定的PID参数进行温度控制……
        //< + 1-打开自调功能-使用自动调整的PID参数进行温度控制；
        uint32_t a3 : 1; //< 类型：系统；名字：加热三段自调功能；格式：……
        //< + 0-关闭自调功能-使用固定的PID参数进行温度控制……
        //< + 1-打开自调功能-使用自动调整的PID参数进行温度控制；
        uint32_t a4 : 1; //< 类型：系统；名字：加热四段自调功能；格式：……
        //< + 0-关闭自调功能-使用固定的PID参数进行温度控制……
        //< + 1-打开自调功能-使用自动调整的PID参数进行温度控制；
        uint32_t a5 : 1; //< 类型：系统；名字：加热五段自调功能；格式：……
        //< + 0-关闭自调功能-使用固定的PID参数进行温度控制……
        //< + 1-打开自调功能-使用自动调整的PID参数进行温度控制；
        uint32_t a6 : 1; //< 类型：系统；名字：加热六段自调功能；格式：……
        //< + 0-关闭自调功能-使用固定的PID参数进行温度控制……
        //< + 1-打开自调功能-使用自动调整的PID参数进行温度控制；
        uint32_t a7 : 1; //< 类型：系统；名字：喷嘴控制模式；格式：……
        //< + 0-开换比例控制-喷嘴使用恒温百分比进行开环加热……
        //< + 1-PID控制-使用PID控制加热；
    } COMMON_PARA21;

    typedef struct {
        uint32_t i0 : 16; //< 类型：系统；名字：喷嘴温度PID调整I值；
        uint32_t i1 : 16; //< 类型：系统；名字：加热一段温度PID调整I值；
        uint32_t i2 : 16; //< 类型：系统；名字：加热二段温度PID调整I值；
        uint32_t i3 : 16; //< 类型：系统；名字：加热三段温度PID调整I值；
        uint32_t i4 : 16; //< 类型：系统；名字：加热四段温度PID调整I值；
        uint32_t i5 : 16; //< 类型：系统；名字：加热五段温度PID调整I值；
        uint32_t i6 : 16; //< 类型：系统；名字：加热六段温度PID调整I值；
        uint32_t ht : 10; //< 类型：系统；名字：最高料温；精度：0；单位：°C；
        uint32_t seg : 4; //< 类型：系统；名字：温度段数；精度：0；单位：sec；
        uint32_t od : 1; //< 类型：系统；名字：自调优化；格式：……
        //< + 0-关闭自动优化功能-温度控制不优化……
        //< + 1-打开自动优化功能-温度控制自动优化；
        uint32_t reserve0 : 1; //< 类型：系统；名字：预留；
    } COMMON_PARA22;

    typedef struct {
        uint32_t d0 : 16; //< 类型：系统；名字：喷嘴温度PID调整D值；
        uint32_t d1 : 16; //< 类型：系统；名字：加热一段温度PID调整D值；
        uint32_t d2 : 16; //< 类型：系统；名字：加热二段温度PID调整D值；
        uint32_t d3 : 16; //< 类型：系统；名字：加热三段温度PID调整D值；
        uint32_t d4 : 16; //< 类型：系统；名字：加热四段温度PID调整D值；
        uint32_t d5 : 16; //< 类型：系统；名字：加热五段温度PID调整D值；
        uint32_t d6 : 16; //< 类型：系统；名字：加热六段温度PID调整D值；
        uint32_t hot : 7; //< 类型：系统；名字：最高油温；精度：0；单位：°C；
        uint32_t oct : 7; //< 类型：系统；名字：油温冷却；精度：0；单位：°C；
        uint32_t reserve0 : 2; //< 类型：系统；名字：预留；
    } COMMON_PARA23;

    typedef struct {
        uint32_t s0 : 16; //< 类型：系统；名字：喷嘴加热速度；精度：0；单位：%；
        uint32_t s1 : 16; //< 类型：系统；名字：加热一段加热速度；精度：0；单位：%；
        uint32_t s2 : 16; //< 类型：系统；名字：加热二段加热速度；精度：0；单位：%；
        uint32_t s3 : 16; //< 类型：系统；名字：加热三段加热速度；精度：0；单位：%；
        uint32_t s4 : 16; //< 类型：系统；名字：加热四段加热速度；精度：0；单位：%；
        uint32_t s5 : 16; //< 类型：系统；名字：加热五段加热速度；精度：0；单位：%；
        uint32_t s6 : 16; //< 类型：系统；名字：加热六段加热速度；精度：0；单位：%；
        uint32_t reserve0 : 16; //< 类型：系统；名字：预留；
    } COMMON_PARA24;

    typedef struct {
        uint32_t c0 : 16; //< 类型：系统；名字：喷嘴温度补偿；精度：0；单位：%；
        uint32_t c1 : 16; //< 类型：系统；名字：加热一段温度补偿；精度：0；单位：%；
        uint32_t c2 : 16; //< 类型：系统；名字：加热二段温度补偿；精度：0；单位：%；
        uint32_t c3 : 16; //< 类型：系统；名字：加热三段温度补偿；精度：0；单位：%；
        uint32_t c4 : 16; //< 类型：系统；名字：加热四段温度补偿；精度：0；单位：%；
        uint32_t c5 : 16; //< 类型：系统；名字：加热五段温度补偿；精度：0；单位：%；
        uint32_t c6 : 16; //< 类型：系统；名字：加热六段温度补偿；精度：0；单位：%；
        uint32_t reserve0 : 16; //< 类型：系统；名字：预留；
    } COMMON_PARA25;

    typedef struct {
        uint32_t blow0 : 1; //< 类型：系统；名字：喷嘴吹风使能；
        uint32_t blow1 : 1; //< 类型：系统；名字：加热一段吹风使能；
        uint32_t blow2 : 1; //< 类型：系统；名字：加热二段吹风使能；
        uint32_t blow3 : 1; //< 类型：系统；名字：加热三段吹风使能；
        uint32_t blow4 : 1; //< 类型：系统；名字：加热四段吹风使能；
        uint32_t blow5 : 1; //< 类型：系统；名字：加热五段吹风使能；
        uint32_t blow6 : 1; //< 类型：系统；名字：加热六段吹风使能；
        uint32_t oil_safe : 1; //< 类型：系统；名字：油温报警使用；
        uint32_t blowout0 : 8; //< 类型：系统；名字：喷嘴吹风输出点选择；
        uint32_t blowout1 : 8; //< 类型：系统；名字：加热一段吹风输出点选择；
        uint32_t blowout2 : 8; //< 类型：系统；名字：加热二段吹风输出点选择；
        /**********************/
        uint32_t blowout3 : 8; //< 类型：系统；名字：加热三段吹风输出点选择；
        uint32_t blowout4 : 8; //< 类型：系统；名字：加热四段吹风输出点选择；
        uint32_t blowout5 : 8; //< 类型：系统；名字：加热五段吹风输出点选择；
        uint32_t blowout6 : 8; //< 类型：系统；名字：加热六段吹风输出点选择；
        /**********************/
        uint32_t blowtemp0 : 4; //< 类型：系统；名字：喷嘴吹风温度偏差；
        uint32_t blowtemp1 : 4; //< 类型：系统；名字：加热一段吹风温度偏差；
        uint32_t blowtemp2 : 4; //< 类型：系统；名字：加热二段吹风温度偏差；
        uint32_t blowtemp3 : 4; //< 类型：系统；名字：加热三段吹风温度偏差；
        uint32_t blowtemp4 : 4; //< 类型：系统；名字：加热四段吹风温度偏差；
        uint32_t blowtemp5 : 4; //< 类型：系统；名字：加热五段吹风温度偏差；
        uint32_t blowtemp6 : 4; //< 类型：系统；名字：加热六段吹风温度偏差；
        uint32_t reserve1 : 4; //< 类型：系统；名字：预留；
    } COMMON_PARA26;

        typedef struct {
        uint32_t thin_p : 16; //< 类型：系统；名字：调模进压力；精度：0；单位：bar；
        uint32_t thick_p : 16; //< 类型：系统；名字：调模退压力；精度：0；单位：bar；
        /**********************/
        uint32_t thin_s : 8; //< 类型：系统；名字：调模进速度；精度：0；单位：%；
        uint32_t thick_s : 8; //< 类型：系统；名字：调模退速度；精度：0；单位：%；
        uint32_t mold_p : 16; //< 类型：系统；名字：调开关模压力；精度：0；单位：bar；
        /**********************/
        uint32_t mold_s : 8; //< 类型：系统；名字：调开关模速度；精度：0；单位：%；
        uint32_t limit_p : 16; //< 类型：系统；名字：限压；精度：0；单位：bar；
        uint32_t limit_s : 8; //< 类型：系统；名字：限速；精度：0；单位：%；
        /**********************/
    } COMMON_PARA27;

    typedef union {
        COMMON_PARA1 para;
        uint32_t all_para[sizeof (COMMON_PARA1) / 4];
    } ACTION_COMMON_PARA1;

    typedef union {
        COMMON_PARA2 para;
        uint32_t all_para[sizeof (COMMON_PARA2) / 4];
    } ACTION_COMMON_PARA2;

    typedef union {
        COMMON_PARA3 para;
        uint32_t all_para[sizeof (COMMON_PARA3) / 4];
    } ACTION_COMMON_PARA3;

    typedef union {
        COMMON_PARA4 para;
        uint32_t all_para[sizeof (COMMON_PARA4) / 4];
    } ACTION_COMMON_PARA4;

    typedef union {
        COMMON_PARA5 para;
        uint32_t all_para[sizeof (COMMON_PARA5) / 4];
    } ACTION_COMMON_PARA5;

    typedef union {
        COMMON_PARA6 para;
        uint32_t all_para[sizeof (COMMON_PARA6) / 4];
    } ACTION_COMMON_PARA6;

    typedef union {
        COMMON_PARA7 para;
        uint32_t all_para[sizeof (COMMON_PARA7) / 4];
    } ACTION_COMMON_PARA7;

    typedef union {
        COMMON_PARA8 para;
        uint32_t all_para[sizeof (COMMON_PARA8) / 4];
    } ACTION_COMMON_PARA8;

    typedef union {
        COMMON_PARA9 para;
        uint32_t all_para[sizeof (COMMON_PARA9) / 4];
    } ACTION_COMMON_PARA9;

    typedef union {
        COMMON_PARA10 para;
        uint32_t all_para[sizeof (COMMON_PARA10) / 4];
    } ACTION_COMMON_PARA10;

    typedef union {
        COMMON_PARA11 para;
        uint32_t all_para[sizeof (COMMON_PARA11) / 4];
    } ACTION_COMMON_PARA11;

    typedef union {
        COMMON_PARA13 para;
        uint32_t all_para[sizeof (COMMON_PARA13) / 4];
    } ACTION_COMMON_PARA13;

    typedef union {
        COMMON_PARA14 para;
        uint32_t all_para[sizeof (COMMON_PARA14) / 4];
    } ACTION_COMMON_PARA14;

    typedef union {
        COMMON_PARA15 para;
        uint16_t all_para16[sizeof (COMMON_PARA15) / 2];
        uint32_t all_para[sizeof (COMMON_PARA15) / 4];
    } ACTION_COMMON_PARA15;

    typedef union {
        COMMON_PARA16 para;
        uint16_t all_para16[sizeof (COMMON_PARA16) / 2];
        uint32_t all_para[sizeof (COMMON_PARA16) / 4];
    } ACTION_COMMON_PARA16;

    typedef union {
        COMMON_PARA17 para;
        uint16_t all_para16[sizeof (COMMON_PARA17) / 2];
        uint32_t all_para[sizeof (COMMON_PARA17) / 4];
    } ACTION_COMMON_PARA17;

    typedef union {
        COMMON_PARA18 para;
        uint16_t all_para16[sizeof (COMMON_PARA18) / 2];
        uint32_t all_para[sizeof (COMMON_PARA18) / 4];
    } ACTION_COMMON_PARA18;

    typedef union {
        COMMON_PARA19 para;
        uint16_t all_para16[sizeof (COMMON_PARA19) / 2];
        uint32_t all_para[sizeof (COMMON_PARA19) / 4];
    } ACTION_COMMON_PARA19;

    typedef union {
        COMMON_PARA20 para;
        uint16_t all_para16[sizeof (COMMON_PARA20) / 2];
        uint32_t all_para[sizeof (COMMON_PARA20) / 4];
    } ACTION_COMMON_PARA20;

    typedef union {
        COMMON_PARA21 para;
        uint16_t all_para16[sizeof (COMMON_PARA21) / 2];
        uint32_t all_para[sizeof (COMMON_PARA21) / 4];
    } ACTION_COMMON_PARA21;

    typedef union {
        COMMON_PARA22 para;
        uint16_t all_para16[sizeof (COMMON_PARA22) / 2];
        uint32_t all_para[sizeof (COMMON_PARA22) / 4];
    } ACTION_COMMON_PARA22;

    typedef union {
        COMMON_PARA23 para;
        uint16_t all_para16[sizeof (COMMON_PARA23) / 2];
        uint32_t all_para[sizeof (COMMON_PARA23) / 4];
    } ACTION_COMMON_PARA23;

    typedef union {
        COMMON_PARA24 para;
        uint16_t all_para16[sizeof (COMMON_PARA24) / 2];
        uint32_t all_para[sizeof (COMMON_PARA24) / 4];
    } ACTION_COMMON_PARA24;

    typedef union {
        COMMON_PARA25 para;
        uint16_t all_para16[sizeof (COMMON_PARA25) / 2];
        uint32_t all_para[sizeof (COMMON_PARA25) / 4];
    } ACTION_COMMON_PARA25;

    typedef union {
        COMMON_PARA26 para;
        uint16_t all_para16[sizeof (COMMON_PARA26) / 2];
        uint32_t all_para[sizeof (COMMON_PARA26) / 4];
    } ACTION_COMMON_PARA26;

    typedef union {
        COMMON_PARA27 para;
        uint16_t all_para16[sizeof (COMMON_PARA27) / 2];
        uint32_t all_para[sizeof (COMMON_PARA27) / 4];
    } ACTION_COMMON_PARA27;


    /******************************************************************************/
    //< 关模详细参数结构

    static const uint32_t mold_close_addr[] = {
        ICAddr_MoldBase_Para0, //<类型：模号；名字：关模一段；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
        ICAddr_MoldBase_Para49, //<类型：系统；名字：；结构：MOLD_CLOSE_PARA；地址：mold_close_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA1 para1[10];
        ACTION_COMMON_PARA2 para2;
        /**********************/
        uint32_t diff_close_en : 1; //< 类型：模号；名字：差动锁模使能；格式：……
        //< + 0-不使用-不使用差动锁模功能……
        //< + 1-使用-使用差动锁模功能；
        uint32_t diff_time : 15; //< 类型：模号；名字：差动锁模延迟时间；精度：2；单位：s；
        uint32_t low_protect : 16; //< 类型：模号；名字：低压保护时间；精度：2；单位：s；
        /**********************/
        uint32_t seg : 4; //< 类型：模号；名字：关模段数设定；精度：0；单位：sec；
        uint32_t reserve0 : 28; //< 类型：模号；名字：预留；
        /**********************/
        uint32_t ctot : 16; //< 类型：模号；名字：关转开延迟时间；精度：2；单位：s；
        uint32_t reserve1 : 16; //< 类型：模号；名字：预留；
        /**********************/
    } MOLD_CLOSE_PARA0;

    typedef union {
        MOLD_CLOSE_PARA0 para;
        uint32_t all_para[sizeof (MOLD_CLOSE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para0, ICAddr_MoldBase_Para49)];
    } MOLD_CLOSE_PARA;
    /******************************************************************************/
    //< 开模详细参数结构
    static const uint32_t mold_open_addr[] = {
        ICAddr_MoldBase_Para50,
        ICAddr_MoldBase_Para99 //<类型：模号；名字：；结构：MOLD_OPEN_PARA；地址：mold_open_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA1 para1[10];
        ACTION_COMMON_PARA2 para2;
        /**********************/
        uint32_t open_protect : 16; //< 类型：模号；名字：开模保护时间；精度：0；单位：s；
        uint32_t mos : 16; //< 类型：模号；名字：开模慢延迟时间；精度：2；单位：s；
        /**********************/
        uint32_t link_en : 1; //< 类型：模号；名字：开模联动；格式：……
        //< + 0-不使用-不使用开模联动功能……
        //< + 1-使用-使用开模联动功能；
        uint32_t seg : 4; //< 类型：模号；名字：开模段数设定；精度：0；单位：sec；
        uint32_t link_pos : 17; //< 类型：模号；名字：联动位置；精度：1；单位：mm；
        uint32_t reserve0 : 10; //< 类型：模号；名字：预留；
        /**********************/
    } MOLD_OPEN_PARA0;

    typedef union {
        MOLD_OPEN_PARA0 para;
        uint32_t all_para[sizeof (MOLD_OPEN_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para50, ICAddr_MoldBase_Para99)];
    } MOLD_OPEN_PARA;
    /******************************************************************************/
    //< 射出详细参数结构
    static const uint32_t inject_in_addr[] = {
        ICAddr_MoldBase_Para100,
        ICAddr_MoldBase_Para199 //<类型：模号；名字：；结构：INJECT_IN_PARA；地址：inject_in_addr；
    };

    typedef union {

        struct {
            uint16_t ijt1; //< 类型：模号；名字：射出一段时间；精度：3；单位：s；
            uint16_t ijt2; //< 类型：模号；名字：射出二段时间；精度：3；单位：s；
            uint16_t ijt3; //< 类型：模号；名字：射出三段时间；精度：3；单位：s；
            uint16_t ijt4; //< 类型：模号；名字：射出四段时间；精度：3；单位：s；
            uint16_t ijt5; //< 类型：模号；名字：射出五段时间；精度：3；单位：s；
            uint16_t ijt6; //< 类型：模号；名字：射出六段时间；精度：3；单位：s；
            uint16_t ijt7; //< 类型：模号；名字：射出七段时间；精度：3；单位：s；
            uint16_t ijt8; //< 类型：模号；名字：射出八段时间；精度：3；单位：s；
            uint16_t ijt9; //< 类型：模号；名字：射出九段时间；精度：3；单位：s；
            uint16_t ijt10; //< 类型：模号；名字：射出十段时间；精度：3；单位：s；
        };
        uint16_t all_para[10];
    } INJECT_IN_PARA3;

    typedef struct {
        ACTION_COMMON_PARA1 para1[10];
        ACTION_COMMON_PARA2 para2;
        INJECT_IN_PARA3 para3;
        /**********************/
        uint32_t total_time : 20; //< 类型：模号；名字：射出总时间；精度：2；单位：s；
        uint32_t mode : 4; //< 类型：模号；名字：射出切保压；格式：……
        //< + 0-位置-以位置为条件切换到保压……
        //< + 1-时间-以时间为条件切换到保压……
        //< + 2-位置或时间-以位置或时间为条件切换到保压；
        uint32_t pre_s : 8; //< 类型：模号；名字：预射胶速度；精度：0；单位：%；
        /**********************/
        uint32_t protect_time : 16; //< 类型：模号；名字：射出保护时间；精度：0；单位：s；
        uint32_t pre_en : 1; //< 类型：模号；名字：预射胶功能；格式：……
        //< + 0-不使用-不使用预射胶功能……
        //< + 1-使用-使用预射胶功能；
        uint32_t pre_mode : 3; //< 类型：模号；名字：预射胶模式；格式：……
        //< + 0-位置-以位置为条件进行预射胶……
        //< + 1-时间-以时间为条件进行预射胶……
        //< + 2-位置或时间-以位置或时间为条件进行预射胶；
        uint32_t pre_time : 12; //< //< 类型：模号；名字：预射胶时间；精度：2；单位：s；
        /**********************/
        uint32_t i_seg : 4; //< 类型：模号；名字：射出段数设定；精度：0；单位：sec；
        uint32_t k_seg : 4; //< 类型：模号；名字：保压段数设定；精度：0；单位：sec；
        uint32_t pre_pos : 16; //< 类型：模号；名字：预射胶位置；精度：1；单位：mm；
        uint32_t reserve2 : 8; //< 类型：模号；名字：预留；
        /**********************/
        ACTION_COMMON_PARA3 para4[10];
        /**********************/
    } INJECT_IN_PARA0;

    typedef union {
        INJECT_IN_PARA0 para;
        uint32_t all_para[sizeof (INJECT_IN_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para100, ICAddr_MoldBase_Para199)];
    } INJECT_IN_PARA;
    /******************************************************************************/
    //< 射前加料详细参数结构
    static const uint32_t before_inject_charge_addr[] = {
        ICAddr_MoldBase_Para200,
        ICAddr_MoldBase_Para208 //<类型：模号；名字：；结构：BEFORE_INJECT_CHARGE_PARA；地址：before_inject_charge_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA4 para1;
        ACTION_COMMON_PARA2 para2;
        /**********************/
    } BEFORE_INJECT_CHARGE_PARA0;

    typedef union {
        BEFORE_INJECT_CHARGE_PARA0 para;
        uint32_t all_para[sizeof (BEFORE_INJECT_CHARGE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para200, ICAddr_MoldBase_Para208)];
    } BEFORE_INJECT_CHARGE_PARA;
    /******************************************************************************/
    //< 加料详细参数结构
    static const uint32_t charge_addr[] = {
        ICAddr_MoldBase_Para209,
        ICAddr_MoldBase_Para231 //<类型：模号；名字：；结构：BEFORE_INJECT_CHARGE_PARA；地址：charge_addr；
    };

    typedef union {

        struct {
            uint16_t cb1; //< 类型：模号；名字：加料一段背压；精度：0；单位：bar；
            uint16_t cb2; //< 类型：模号；名字：加料二段背压；精度：0；单位：bar；
            uint16_t cb3; //< 类型：模号；名字：加料三段背压；精度：0；单位：bar；
            uint16_t cb4; //< 类型：模号；名字：加料四段背压；精度：0；单位：bar；
        };
        uint16_t all_para[4];
    } CHARGE_PARA3;

    typedef struct {
        ACTION_COMMON_PARA1 para1[4];
        ACTION_COMMON_PARA2 para2;
        CHARGE_PARA3 para3;
        /**********************/
        uint32_t time : 16; //< 类型：模号；名字：加料保护时间；精度：0；单位：s；
        uint32_t bm : 4; //< 类型：模号；名字：背压控制模式；格式：……
        //< + 0-系统比例-背压输出跟系统比例一样……
        //< + 1-手动-背压由手动调整并固定……
        //< + 2-独立-背压独立输出；
        uint32_t seg : 4; //< 类型：模号；名字：加料段数设定；精度：0；单位：sec；
        uint32_t reserve0 : 8; //< 类型：模号；名字：预留；
        /**********************/
        uint32_t tc : 8; //< 类型：系统；名字：加料感应齿/转；
        uint32_t reserve1 : 24; //< 类型：系统；名字：预留；
        /**********************/
    } CHARGE_PARA0;

    typedef union {
        CHARGE_PARA0 para;
        uint32_t all_para[sizeof (CHARGE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para209, ICAddr_MoldBase_Para231)];
    } CHARGE_PARA;
    /******************************************************************************/
    static const uint32_t cool_addr[] = {
        ICAddr_MoldBase_Para232,
        ICAddr_MoldBase_Para232 //<类型：模号；名字：；结构：COOL_PARA；地址：cool_addr；
    };
    //< 冷却详细参数结构

    typedef struct {
        uint32_t time : 16; //< 类型：模号；名字：模具冷却时间；精度：2；单位：s；
        uint32_t acc_en : 1; //< 类型：模号；名字：冷却完加料；格式：……
        //< + 0-正常加料-冷却时间未结束可以进行加料……
        //< + 1-冷却完加料-冷却时间结束后才进行加料；
        uint32_t pre_press : 15; //< 类型：模号；名字：预射胶压力；精度：0；单位：bar；
        /**********************/
    } COOL_PARA0;

    typedef union {
        COOL_PARA0 para;
        uint32_t all_para[sizeof (COOL_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para232, ICAddr_MoldBase_Para232)];
    } COOL_PARA;
    /******************************************************************************/
    //< 前松退详细参数结构
    static const uint32_t front_suckback_addr[] = {
        ICAddr_MoldBase_Para233,
        ICAddr_MoldBase_Para239 //<类型：模号；名字：；结构：FRONT_SUCKBACK_PARA0；地址：front_suckback_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA1 para1;
        ACTION_COMMON_PARA2 para2;
        /**********************/
        uint32_t reserve0; //< 类型：模号；名字：预留；
        /**********************/
    } FRONT_SUCKBACK_PARA0;

    typedef union {
        FRONT_SUCKBACK_PARA0 para;
        uint32_t all_para[sizeof (FRONT_SUCKBACK_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para233, ICAddr_MoldBase_Para239)];
    } FRONT_SUCKBACK_PARA;
    /******************************************************************************/
    //< 后松退详细参数结构
    static const uint32_t after_suckback_addr[] = {
        ICAddr_MoldBase_Para240,
        ICAddr_MoldBase_Para246 //<类型：模号；名字：；结构：AFTER_SUCKBACK_PARA；地址：after_suckback_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA5 para1;
        ACTION_COMMON_PARA2 para2;
        /**********************/
        uint32_t reserve0; //< 类型：模号；名字：预留；
        /**********************/
    } AFTER_SUCKBACK_PARA0;

    typedef union {
        AFTER_SUCKBACK_PARA0 para;
        uint32_t all_para[sizeof (AFTER_SUCKBACK_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para240, ICAddr_MoldBase_Para246)];
    } AFTER_SUCKBACK_PARA;
    /******************************************************************************/
    //< 顶进详细参数结构
    static const uint32_t eject_adv_addr[] = {
        ICAddr_MoldBase_Para247,
        ICAddr_MoldBase_Para258 //<类型：模号；名字：；结构：EJECT_ADV_PARA；地址：eject_adv_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA1 para1[2];
        ACTION_COMMON_PARA2 para2;
        /**********************/
        uint32_t time1 : 16; //< 类型：模号；名字：开模转顶出时间；精度：2；单位：s；
        uint32_t reserve0 : 16; //< 类型：模号；名字：预留；
        /**********************/
    } EJECT_ADV_PARA0;

    typedef union {
        EJECT_ADV_PARA0 para;
        uint32_t all_para[sizeof (EJECT_ADV_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para247, ICAddr_MoldBase_Para258)];
    } EJECT_ADV_PARA;
    /******************************************************************************/
    //< 顶退详细参数结构
    static const uint32_t eject_ret_addr[] = {
        ICAddr_MoldBase_Para259,
        ICAddr_MoldBase_Para270 //<类型：模号；名字：；结构：EJECT_RET_PARA；地址：eject_ret_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA1 para1[2];
        ACTION_COMMON_PARA2 para2;
        /**********************/
    } EJECT_RET_PARA0;

    typedef union {
        EJECT_RET_PARA0 para;
        uint32_t all_para[sizeof (EJECT_RET_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para259, ICAddr_MoldBase_Para270)];
    } EJECT_RET_PARA;
    /******************************************************************************/
    //< 吹气详细参数结构
    static const uint32_t blow_addr[] = {
        ICAddr_MoldBase_Para271,
        ICAddr_MoldBase_Para282 //<类型：模号；名字：；结构：BLOW_PARA；地址：blow_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA6 para1[6];
        /**********************/
    } BLOW_PARA0;

    typedef union {
        BLOW_PARA0 para;
        uint32_t all_para[sizeof (BLOW_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para271, ICAddr_MoldBase_Para282)];
    } BLOW_PARA;
    /******************************************************************************/
    //< 抽芯详细参数结构
    static const uint32_t core_addr[] = {
        ICAddr_MoldBase_Para283,
        ICAddr_MoldBase_Para315 //<类型：模号；名字：；结构：ALL_CORE_PARA；地址：core_addr；
    };

    typedef struct {
        uint32_t cfa : 2; //< 类型：模号；名字：抽芯A功能；格式：……
        //< + 0-蕊心-抽芯A使用蕊心……
        //< + 1-绞牙-抽芯A使用绞牙；
        uint32_t cfb : 2; //< 类型：模号；名字：抽芯B功能；格式：……
        //< + 0-蕊心-抽芯B使用蕊心……
        //< + 1-绞牙-抽芯B使用绞牙；
        uint32_t cfc : 2; //< 类型：模号；名字：抽芯C功能；格式：……
        //< + 0-蕊心-抽芯C使用蕊心……
        //< + 1-绞牙-抽芯C使用绞牙；
        uint32_t cfd : 2; //< 类型：模号；名字：抽芯D功能；格式：……
        //< + 0-蕊心-抽芯D使用蕊心……
        //< + 1-绞牙-抽芯D使用绞牙；
        uint32_t csp : 1; //< 类型：模号；名字：抽芯入自保；格式：……
        //< + 0-使用-射出时候抽芯阀打开……
        //< + 1-不使用-射出时候抽芯阀不打开；
        uint32_t sf : 1; //< 类型：模号；名字：特殊功能；格式：……
        //< + 0-使用-使用根据实际情况修改的特殊功能……
        //< + 1-不使用-不使用根据实际情况修改的特殊功能；
        uint32_t ss : 11; //< 类型：模号；名字：减速速度；精度：0；单位：%；
        uint32_t st : 11; //< 类型：模号；名字：减速齿数；精度：0；单位：pc；
        /**********************/
        uint32_t sp : 16; //< 类型：模号；名字：减速压力；精度：0；单位：bar；
        uint32_t ss1 : 8; //< 类型：模号；名字：减速1速度；精度：0；单位：%；
        uint32_t ss2 : 8; //< 类型：模号；名字：减速2速度；精度：0；单位：%；
        /**********************/
        uint32_t sp1 : 16; //< 类型：模号；名字：减速1行程；精度：1；单位：mm；
        uint32_t sp2 : 16; //< 类型：模号；名字：减速2行程；精度：1；单位：mm；

    } CORE_FUNC_PARA0;

    typedef struct {
        ACTION_COMMON_PARA7 para1[8];
        ACTION_COMMON_PARA11 para2;
        CORE_FUNC_PARA0 para3;
        /**********************/
    } CORE_PARA0;

    typedef union {
        CORE_PARA0 para;
        uint32_t all_para[sizeof (CORE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para283, ICAddr_MoldBase_Para315)];
    } ALL_CORE_PARA;
    /******************************************************************************/
    //< 座进详细参数结构
    static const uint32_t nozzle_adv_addr[] = {
        ICAddr_MoldBase_Para316,
        ICAddr_MoldBase_Para327 //<类型：模号；名字：；结构：NOZZLE_ADV_PARA；地址：nozzle_adv_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA1 para1[2];
        ACTION_COMMON_PARA2 para2;
        /**********************/
        uint32_t time : 16; //< 类型：模号；名字：座进保护时间；精度：0；单位：s；
        uint32_t reserve0 : 16; //< 类型：模号；名字：预留
        /**********************/
        uint32_t zd : 1; //< 类型：系统；名字：射座归零方向；格式：……
        //< + 0-前进-座台前进为0方向……
        //< + 1-后退-座台后退为0方向；
        uint32_t reserve1 : 31; //< 类型：系统；名字：预留
        /**********************/
    } NOZZLE_ADV_PARA0;

    typedef union {
        NOZZLE_ADV_PARA0 para;
        uint32_t all_para[sizeof (NOZZLE_ADV_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para316, ICAddr_MoldBase_Para327)];
    } NOZZLE_ADV_PARA;
    /******************************************************************************/
    //< 座退详细参数结构
    static const uint32_t nozzle_ret_addr[] = {
        ICAddr_MoldBase_Para328,
        ICAddr_MoldBase_Para335 //<类型：模号；名字：；结构：NOZZLE_RET_PARA；地址：nozzle_ret_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA1 para1;
        ACTION_COMMON_PARA2 para2;
        /**********************/
        uint32_t mode : 4; //< 类型：模号；名字：座退控制模式；格式：……
        //< + 0-时间-座退控制使用时间……
        //< + 1-限位-座退控制使用限位开关；
        uint32_t time : 16; //< 类型：模号；名字：座退时间；精度：2；单位：s；
        uint32_t nlen : 1; //< 类型：模号；名字：手动座退无限制
        uint32_t reserve0 : 11; //< 类型：模号；名字：预留
        /**********************/
    } NOZZLE_RET_PARA0;

    typedef union {
        NOZZLE_RET_PARA0 para;
        uint32_t all_para[sizeof (NOZZLE_RET_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para328, ICAddr_MoldBase_Para335)];
    } NOZZLE_RET_PARA;
    /******************************************************************************/
    //< 调模详细参数结构
    static const uint32_t mold_adjust_addr[] = {
        ICAddr_MoldBase_Para336,
        ICAddr_MoldBase_Para354 //<类型：模号；名字：；结构：MOLD_ADJUST_PARA；地址：mold_adjust_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA8 m_a; //< 手调模
        ACTION_COMMON_PARA27 a_a; //< 自调模
        ACTION_COMMON_PARA10 para3;
        /**********************/
        uint32_t mode : 1; //< 类型：系统；名字：调模模式；格式：……
        //< + 0-时间-自动调模使用计时方式……
        //< + 1-计齿-自动调模使用计齿方式；
        uint32_t c_tooth : 10; //< 类型：系统；名字：粗调齿数；精度：0；单位：pc；
        uint32_t f_tooth : 10; //< 类型：系统；名字：微调齿数；精度：0；单位：pc；
        uint32_t delay_time : 11; //< 类型：系统；名字：自调模延迟时间；精度：2；单位：s；
        /**********************/
        uint32_t c_time : 16; //< 类型：系统；名字：粗调时间；精度：2；单位：s；
        uint32_t f_time : 16; //< 类型：系统；名字：微调时间；精度：2；单位：s；
        /**********************/
        uint32_t mc_time : 16; //< 类型：系统；名字：自调关模限时；精度：2；单位：s；
        uint32_t athin_time : 16; //< 类型：系统；名字：自调模进限时；精度：2；单位：s；
        /**********************/
        uint32_t athick_time : 16; //< 类型：系统；名字：自调模退时间；精度：2；单位：s；
        uint32_t end_time : 16; //< 类型：系统；名字：自调模结束调模退时间；精度：2；单位：s；
        /**********************/
        uint32_t befp0 : 16; //< 类型：系统；名字：调模退比例阀前延迟；精度：2；单位：s；
        uint32_t aftp0 : 16; //< 类型：系统；名字：调模退比例阀后延迟；精度：2；单位：s；
        /**********************/
        uint32_t befp1 : 16; //< 类型：系统；名字：调模进比例阀前延迟；精度：2；单位：s；
        uint32_t aftp1 : 16; //< 类型：系统；名字：调模进比例阀后延迟；精度：2；单位：s；
        /**********************/
        uint32_t pu0 : 10; //< 类型：系统；名字：调模退压力上升斜率；
        uint32_t pd0 : 10; //< 类型：系统；名字：调模退压力下降斜率；
        uint32_t su0 : 10; //< 类型：系统；名字：调模退速度上升斜率；
        uint32_t reserve0 : 2; //< 类型：系统；名字：预留
        /**********************/
        uint32_t sd0 : 10; //< 类型：系统；名字：调模退速度下降斜率；
        uint32_t pu1 : 10; //< 类型：系统；名字：调模进压力上升斜率；
        uint32_t pd1 : 10; //< 类型：系统；名字：调模进压力下降斜率；
        uint32_t reserve1 : 2; //< 类型：系统；名字：预留
        /**********************/
        uint32_t su1 : 10; //< 类型：系统；名字：调模进速度上升斜率；
        uint32_t sd1 : 10; //< 类型：系统；名字：调模进速度下降斜率；
        uint32_t reserve2 : 12; //< 类型：系统；名字：预留
        /**********************/
    } MOLD_ADJUST_PARA0;

    typedef union {
        MOLD_ADJUST_PARA0 para;
        uint32_t all_para[sizeof (MOLD_ADJUST_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para336, ICAddr_MoldBase_Para354)];
    } MOLD_ADJUST_PARA;
    /******************************************************************************/
    //< 自动清料详细参数结构
    static const uint32_t autopurge_addr[] = {
        ICAddr_MoldBase_Para355,
        ICAddr_MoldBase_Para365 //<类型：模号；名字：；结构：AUTOPURGE_PARA；地址：autopurge_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA9 para1[4];
        /**********************/
        uint32_t cnt : 8; //< 类型：模号；名字：清料次数；精度：0；单位：times；
        uint32_t delay : 16; //< 类型：模号；名字：自清料前延迟；精度：2；单位：s；
        uint32_t reserve0 : 8; //< 类型：模号；名字：预留；
        /**********************/
    } AUTOPURGE_PARA0;

    typedef union {
        AUTOPURGE_PARA0 para;
        uint32_t all_para[sizeof (AUTOPURGE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para355, ICAddr_MoldBase_Para365)];
    } AUTOPURGE_PARA;
    /******************************************************************************/
    //< 自动运行详细参数结构
    static const uint32_t autorun_addr[] = {
        ICAddr_MoldBase_Para366,
        ICAddr_MoldBase_Para375 //<类型：模号；名字：；结构：AUTORUN_PARA；地址：autorun_addr；
    };

    typedef struct {
        COMMON_PARA12 other;
        /**********************/
        uint32_t cp : 16; //< 类型：模号；名字：周期保护时间；精度：0；单位：s；
        uint32_t ep : 16; //< 类型：模号；名字：异常保护时间；精度：0；单位：s；
        /**********************/
        uint32_t charge_mode : 4; //< 类型：模号；名字：加料模式；格式：……
        //< + 0-固定加料-自动运行期间座进后不座退……
        //< + 1-前加料-自动运行期间座退之前加料……
        //< + 2-后加料-自动运行期间座退之后加料；
        uint32_t eject_mode : 4; //< 类型：模号；名字：顶针模式；格式：……
        //< + 0-不用-不使用顶针功能……
        //< + 1-重复-顶针先顶出到顶进终点，然后再顶退到顶退终点，再顶出的来回动作。……
        //< + 2-震动-顶针先顶出到顶进终点，顶退并不退到顶退终点，再顶出的来回动作。
        //< + 3-停留-在半自动模式下托模时，顶进完结束整个循环或手动托模，等下一个循环时在顶退。；
        uint32_t eject_cnt : 8; //< 类型：模号；名字：顶出次数；精度：0；单位：times；
        uint32_t rh_en : 1; //< 类型：模号；名字：取出机；格式：……
        //< + 0-不使用-不使用机械手功能……
        //< + 1-使用-使用取出机功能；
        uint32_t r_cyc : 15; //< 类型：模号；名字：再循环计时；精度：2；单位：s；
        /**********************/
    } AUTORUN_PARA0;

    typedef union {
        AUTORUN_PARA0 para;
        uint32_t all_para[sizeof (AUTORUN_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para366, ICAddr_MoldBase_Para375)];
    } AUTORUN_PARA;
    /******************************************************************************/
    //< 润滑参数结构
    static const uint32_t force_lubricate_addr[] = {
        ICAddr_MoldBase_Para376,
        ICAddr_MoldBase_Para379 //<类型：模号；名字：；结构：FOECE_BULICATE_PARA；地址：force_lubricate_addr；
    };

    typedef struct {
        uint32_t fl_t : 16; //< 类型：模号；名字：润滑时间；精度：2；单位：s；
        uint32_t flc_t : 16; //< 类型：模号；名字：润滑检测时间；精度：2；单位：s；
        /**********************/
        uint32_t fl_m : 24; //< 类型：模号；名字：润滑模数；
        uint32_t s_en : 1; //< 类型：模号；名字：开机润滑功能；格式：……
        //< + 0-不使用-开机之后不润滑……
        //< + 1-使用-开机后，第一次开马达润滑一次；
        uint32_t reserve0 : 7; //< 类型：模号；名字：预留；
        /**********************/
    } FOECE_BULICATE_PARA0;

    typedef union {
        FOECE_BULICATE_PARA0 para;
        uint32_t all_para[sizeof (FOECE_BULICATE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para376, ICAddr_MoldBase_Para379)];
    } FOECE_BULICATE_PARA;
    /******************************************************************************/
    //< 生产管理参数结构
    static const uint32_t product_addr[] = {
        ICAddr_MoldBase_Para380,
        ICAddr_MoldBase_Para399 //<类型：模号；名字：；结构：PRODUCT_PARA；地址：product_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA13 tv; //目标值
        ACTION_COMMON_PARA14 cv; //当前值
        ACTION_COMMON_PARA15 qv; //品管值
        ACTION_COMMON_PARA16 qt; //公差值
        /**********************/
        uint32_t mhn : 8; //< 类型：模号；名字：模穴数；
        uint32_t ie_en : 1; //< 类型：模号；名字：射出终点功能选择；格式：……
        //< + 0-不使用-不使用射出终点来判断良劣品……
        //< + 1-使用-使用射出终点来判断良劣品；
        uint32_t ce_en : 1; //< 类型：模号；名字：加料终点功能选择；格式：……
        //< + 0-不使用-不使用加料终点来判断良劣品……
        //< + 1-使用-使用加料终点来判断良劣品；
        uint32_t me_en : 1; //< 类型：模号；名字：开模终点功能选择；格式：……
        //< + 0-不使用-不使用开模终点来判断良劣品……
        //< + 1-使用-使用开模终点来判断良劣品；
        uint32_t ct_en : 1; //< 类型：模号；名字：周期时间功能选择；格式：……
        //< + 0-不使用-不使用周期时间来判断良劣品……
        //< + 1-使用-使用周期时间来判断良劣品；
        uint32_t tps : 1; //< 类型：模号；名字：生产总数停机选择；格式：……
        //< + 0-不使用-达到生产总数不停止生产……
        //< + 1-使用-达到生产总数停止生产；
        uint32_t gps : 1; //< 类型：模号；名字：良品数停机选择；格式：……
        //< + 0-不使用-达到良品数不停止生产……
        //< + 1-使用-达到良品数停止生产；
        uint32_t bps : 1; //< 类型：模号；名字：劣品数停机选择；格式：……
        //< + 0-不使用-达到劣品数不停止生产……
        //< + 1-使用-达到劣品数停止生产；
        uint32_t mps : 1; //< 类型：模号；名字：装箱模数停机选择；格式：……
        //< + 0-不使用-达到装箱模数不停止生产……
        //< + 1-使用-达到装箱模数停止生产；
        uint32_t rb_en : 1; //< 类型：模号；名字：连列数品管；格式：……
        //< + 0-不使用-连续出现劣品不停机……
        //< + 1-使用-连续出现劣品停机；
        uint32_t r_end : 1; //< 类型：模号；名字：品质参数读取完毕；
        uint32_t tp_tips : 1; //< 类型：模号；名字：生产总数提示选择；格式：……
        //< + 0-不使用-达到生产总数不提示……
        //< + 1-使用-达到生产总数警报提示2秒钟，不停止生产；
        uint32_t gp_tips : 1; //< 类型：模号；名字：良品数提示选择；格式：……
        //< + 0-不使用-达到良品数不提示……
        //< + 1-使用-达到良品数警报提示2秒钟，不停止生产；
        uint32_t bp_tips : 1; //< 类型：模号；名字：劣品数提示选择；格式：……
        //< + 0-不使用-达到劣品数不提示……
        //< + 1-使用-达到劣品数警报提示2秒钟，不停止生产；
        uint32_t mp_tips : 1; //< 类型：模号；名字：装箱模数提示选择；格式：……
        //< + 0-不使用-达到装箱模数不提示……
        //< + 1-使用-达到装箱模数警报提示2秒钟，不停止生产；
        uint32_t tips_time : 4; //< 类型：模号；名字：提示时间设定；精度：0；单位：s
        uint32_t aoen:1;//< 类型：模号；名字：报警输出定时使能；
        uint32_t aot:5;//< 类型：模号；名字：报警输出定时时间选择；
        /**********************/
    } PRODUCT_PARA0;

    typedef union {
        PRODUCT_PARA0 para;
        uint32_t all_para[sizeof (PRODUCT_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para380, ICAddr_MoldBase_Para399)];
    } PRODUCT_PARA;
    /******************************************************************************/
    //< 电眼功能参数结构
    static const uint32_t electric_eye_addr[] = {
        ICAddr_MoldBase_Para400,
        ICAddr_MoldBase_Para404 //<类型：模号；名字：；结构：ELECTRIC_EYE_PARA；地址：electric_eye_addr；
    };

    typedef struct {
        uint32_t eye_protect : 16; //< 类型：模号；名字：电眼保护时间；精度：2；单位：s；
        uint32_t eye_shut_out : 16; //< 类型：模号；名字：电眼遮住时间；精度：2；单位：s；
        /**********************/
        uint32_t en : 1; //< 类型：模号；名字：电眼侦测功能使能；格式：……
        //< + 0-不使用-不使用电眼侦测功能……
        //< + 1-使用-使用电眼侦测功能；
        uint32_t reserve0 : 31; //< 类型：模号；名字：预留；
        /**********************/
    } ELECTRIC_EYE_PARA0;

    typedef union {
        ELECTRIC_EYE_PARA0 para;
        uint32_t all_para[sizeof (ELECTRIC_EYE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para400, ICAddr_MoldBase_Para404)];
    } ELECTRIC_EYE_PARA;
    /******************************************************************************/
    //< 马达参数结构
    static const uint32_t motor_addr[] = {
        ICAddr_MoldBase_Para405,
        ICAddr_MoldBase_Para409 //<类型：系统；名字：；结构：MOTOR_PARA；地址：motor_addr；
    };

    typedef struct {
        uint32_t mrpt : 16; //< 类型：系统；名字：马达启动保护时间；精度：2；单位：s；
        uint32_t mopt : 16; //< 类型：系统；名字：马达过载保护时间；精度：2；单位：s；
        uint32_t mrdt : 16; //< 类型：系统；名字：马达启动延迟时间；精度：2；单位：s；
        uint32_t sdst : 16; //< 类型：系统；名字：星三角启动时间；精度：2；单位：s；
        /**********************/
        uint32_t mode : 4; //< 类型：系统；名字：马达控制模式；格式：……
        //< + 0-非油压模式-无DA输出……
        //< + 1-串口485/232通讯-无；
        //< + 2-模拟给定-模拟量控制；
        //< + 3-预留2-无；
        //< + 4-CAN通讯给定-CAN通讯控制；
        uint32_t can_v : 4; //< 类型：系统；名字：变频器厂家；格式：……
        //< + 0-无-不选择变频器厂家……
        //< + 1-精一电控-使用精一变频器；
        //< + 2-四方电气-使用四方电气变频器；
        //< + 3-星辰伺服-使用星辰变频器；
        //< + 4-星辰（油电混合）-使用星辰变频器；
        //< + 5-翼科（油电混合）-使用翼科伺服；
        uint32_t s_en : 1; //< 类型：系统；名字：星三角启动使能；格式：……
        //< + 0-不使用-不使用星三角启动功能……
        //< + 1-使用-使用星三角启动；
        uint32_t reserve0 : 23; //< 类型：系统；
        /**********************/
    } MOTOR_PARA0;

    typedef union {
        MOTOR_PARA0 para;
        uint32_t all_para[sizeof (MOTOR_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para405, ICAddr_MoldBase_Para409)];
    } MOTOR_PARA;
    /******************************************************************************/
    //< 温度参数结构
    static const uint32_t temperature_addr[] = {
        ICAddr_MoldBase_Para410,
        ICAddr_MoldBase_Para499 //<类型：模号；名字：；结构：TEMPERATURE_PARA；地址：temperature_addr；
    };

    typedef struct {
        ACTION_COMMON_PARA17 h; //< 加热值
        ACTION_COMMON_PARA18 k; //< 保温值
        ACTION_COMMON_PARA19 u; //< 上偏差
        ACTION_COMMON_PARA20 b; //< 下偏差
        ACTION_COMMON_PARA21 p; //< P值
        ACTION_COMMON_PARA22 i; //< I值
        ACTION_COMMON_PARA23 d; //< D值
        ACTION_COMMON_PARA24 s; //< 加热速度
        ACTION_COMMON_PARA25 c; //< 加热补偿
        /**********************/
        uint32_t nc : 10; //< 类型：模号；名字：喷嘴恒温周期；精度：1；单位：s；
        uint32_t np : 7; //< 类型：模号；名字：喷嘴恒温百分比；精度：0；单位：%；
        uint32_t st : 7; //< 类型：模号；名字：镙杆保护时间；精度：0；单位：min；
        uint32_t mode : 4; //< 类型：模号；名字：加热模式；格式：……
        //< + 0-不加热-关闭加热……
        //< + 1-加热-启动加热……
        //< + 2-保温-启动保温……
        //< + 3-自动保温-启动自动保温……
        //< + 4-自动加热-启动自动加热；
        uint32_t ach : 1; //< 类型：模号；名字：警报切加热；格式：……
        //< + 0-不使用-不使警报切加热功能……
        //< + 1-使用-使用警报切加热，报警计时到后，自动切断加热；
        uint32_t ack : 1; //< 类型：模号；名字：警报切保温；格式：……
        //< + 0-不使用-不使警报切保温功能……
        //< + 1-使用-使用警报切保温，报警计时到后，自动切换到保温模式；
        uint32_t sp : 1; //< 类型：模号；名字：镙杆保护功能；格式：……
        //< + 0-不使用-不使用镙杆保护功能……
        //< + 1-使用-使用镙杆保护功能，达到设定温度下偏差后，开始计时镙杆保护时间，在保护时间内，禁止镙杆动作；
        uint32_t reserve0 : 1; //< 类型：模号；
        /**********************/
        ACTION_COMMON_PARA26 blow;//< 吹风功能
    } TEMPERATURE_PARA0;

    typedef union {
        TEMPERATURE_PARA0 para;
        uint32_t all_para[sizeof (TEMPERATURE_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_MoldBase_Para410, ICAddr_MoldBase_Para499)];
    } TEMPERATURE_PARA;
    /******************************************************************************/

    /******************************************************************************/
    typedef struct {
        uint32_t e0 : 16; //< 类型：系统；名字：动模电子尺长度；精度：1；单位：mm；
        uint32_t e1 : 16; //< 类型：系统；名字：射出电子尺长度；精度：1；单位：mm；
        uint32_t e2 : 16; //< 类型：系统；名字：座台电子尺长度；精度：1；单位：mm；
        uint32_t e3 : 16; //< 类型：系统；名字：顶针电子尺长度；精度：1；单位：mm；
    } ADJUSTMENT0;

    typedef struct {
        uint32_t o0 : 16; //< 类型：系统；名字：动模油缸行程；精度：1；单位：mm；
        uint32_t o1 : 16; //< 类型：系统；名字：射出油缸行程；精度：1；单位：mm；
        uint32_t o2 : 16; //< 类型：系统；名字：座台油缸行程；精度：1；单位：mm；
        uint32_t o3 : 16; //< 类型：系统；名字：顶针油缸行程；精度：1；单位：mm；
    } ADJUSTMENT1;

    typedef struct {
        uint32_t x0 : 16; //< 类型：系统；名字：动模油缸最大AD值；
        uint32_t x1 : 16; //< 类型：系统；名字：射出油缸最大AD值；
        uint32_t x2 : 16; //< 类型：系统；名字：座台油缸最大AD值；
        uint32_t x3 : 16; //< 类型：系统；名字：顶针油缸最大AD值；
    } ADJUSTMENT2;

    typedef struct {
        uint32_t n0 : 16; //< 类型：系统；名字：动模油缸最小AD值；
        uint32_t n1 : 16; //< 类型：系统；名字：射出油缸最小AD值；
        uint32_t n2 : 16; //< 类型：系统；名字：座台油缸最小AD值；
        uint32_t n3 : 16; //< 类型：系统；名字：顶针油缸最小AD值；
    } ADJUSTMENT3;

    typedef struct {
        uint32_t n1 : 16; //< 类型：系统；名字：设定1段系统压；精度：0；单位：bar；
        uint32_t n2 : 16; //< 类型：系统；名字：设定2段系统压；精度：0；单位：bar；
        uint32_t n3 : 16; //< 类型：系统；名字：设定3段系统压；精度：0；单位：bar；
        uint32_t n4 : 16; //< 类型：系统；名字：设定4段系统压；精度：0；单位：bar；
        uint32_t n5 : 16; //< 类型：系统；名字：设定5段系统压；精度：0；单位：bar；
        uint32_t n6 : 16; //< 类型：系统；名字：设定6段系统压；精度：0；单位：bar；
        uint32_t n7 : 16; //< 类型：系统；名字：设定7段系统压；精度：0；单位：bar；
        uint32_t n8 : 16; //< 类型：系统；名字：设定8段系统压；精度：0；单位：bar；
        uint32_t n9 : 16; //< 类型：系统；名字：设定9段系统压；精度：0；单位：bar；
        uint32_t n10 : 16; //< 类型：系统；名字：设定10段系统压；精度：0；单位：bar；
        uint32_t n11 : 16; //< 类型：系统；名字：设定11段系统压；精度：0；单位：bar；
        uint32_t n12 : 16; //< 类型：系统；名字：设定12段系统压；精度：0；单位：bar；
        uint32_t n13 : 16; //< 类型：系统；名字：设定13段系统压；精度：0；单位：bar；
        uint32_t n14 : 16; //< 类型：系统；名字：设定14段系统压；精度：0；单位：bar；
        uint32_t n15 : 16; //< 类型：系统；名字：设定15段系统压；精度：0；单位：bar；
        uint32_t n16 : 16; //< 类型：系统；名字：设定16段系统压；精度：0；单位：bar；
        uint32_t n17 : 16; //< 类型：系统；名字：设定17段系统压；精度：0；单位：bar；
        uint32_t n18 : 16; //< 类型：系统；名字：设定18段系统压；精度：0；单位：bar；
        uint32_t n19 : 16; //< 类型：系统；名字：设定19段系统压；精度：0；单位：bar；
        uint32_t n20 : 16; //< 类型：系统；名字：设定20段系统压；精度：0；单位：bar；
        uint32_t n0 : 16; //< 类型：系统；名字：设定系统压最大值；精度：0；单位：bar；
        uint32_t reserve0 : 16; //< 类型：系统；名字：预留；
    } ADJUSTMENT4;

    typedef struct {
        uint32_t n1 : 16; //< 类型：系统；名字：设定1段速度；精度：0；单位：%；
        uint32_t n2 : 16; //< 类型：系统；名字：设定2段速度；精度：0；单位：%；
        uint32_t n3 : 16; //< 类型：系统；名字：设定3段速度；精度：0；单位：%；
        uint32_t n4 : 16; //< 类型：系统；名字：设定4段速度；精度：0；单位：%；
        uint32_t n5 : 16; //< 类型：系统；名字：设定5段速度；精度：0；单位：%；
        uint32_t n6 : 16; //< 类型：系统；名字：设定6段速度；精度：0；单位：%；
        uint32_t n7 : 16; //< 类型：系统；名字：设定7段速度；精度：0；单位：%；
        uint32_t n8 : 16; //< 类型：系统；名字：设定8段速度；精度：0；单位：%；
        uint32_t n9 : 16; //< 类型：系统；名字：设定9段速度；精度：0；单位：%；
        uint32_t n10 : 16; //< 类型：系统；名字：设定10段速度；精度：0；单位：%；
        uint32_t n11 : 16; //< 类型：系统；名字：设定11段速度；精度：0；单位：%；
        uint32_t n12 : 16; //< 类型：系统；名字：设定12段速度；精度：0；单位：%；
        uint32_t n13 : 16; //< 类型：系统；名字：设定13段速度；精度：0；单位：%；
        uint32_t n14 : 16; //< 类型：系统；名字：设定14段速度；精度：0；单位：%；
        uint32_t n15 : 16; //< 类型：系统；名字：设定15段速度；精度：0；单位：%；
        uint32_t n16 : 16; //< 类型：系统；名字：设定16段速度；精度：0；单位：%；
        uint32_t n17 : 16; //< 类型：系统；名字：设定17段速度；精度：0；单位：%；
        uint32_t n18 : 16; //< 类型：系统；名字：设定18段速度；精度：0；单位：%；
        uint32_t n19 : 16; //< 类型：系统；名字：设定19段速度；精度：0；单位：%；
        uint32_t n20 : 16; //< 类型：系统；名字：设定20段速度；精度：0；单位：%；
        uint32_t n0 : 16; //< 类型：系统；名字：设定速度最大值；精度：0；单位：%；
        uint32_t reserve0 : 16; //< 类型：系统；名字：预留；
    } ADJUSTMENT5;

    typedef struct {
        uint32_t n1 : 16; //< 类型：系统；名字：设定1段背压；精度：0；单位：bar；
        uint32_t n2 : 16; //< 类型：系统；名字：设定2段背压；精度：0；单位：bar；
        uint32_t n3 : 16; //< 类型：系统；名字：设定3段背压；精度：0；单位：bar；
        uint32_t n4 : 16; //< 类型：系统；名字：设定4段背压；精度：0；单位：bar；
        uint32_t n5 : 16; //< 类型：系统；名字：设定5段背压；精度：0；单位：bar；
        uint32_t n6 : 16; //< 类型：系统；名字：设定6段背压；精度：0；单位：bar；
        uint32_t n7 : 16; //< 类型：系统；名字：设定7段背压；精度：0；单位：bar；
        uint32_t n8 : 16; //< 类型：系统；名字：设定8段背压；精度：0；单位：bar；
        uint32_t n9 : 16; //< 类型：系统；名字：设定9段背压；精度：0；单位：bar；
        uint32_t n10 : 16; //< 类型：系统；名字：设定10段背压；精度：0；单位：bar；
        uint32_t n11 : 16; //< 类型：系统；名字：设定11段背压；精度：0；单位：bar；
        uint32_t n12 : 16; //< 类型：系统；名字：设定12段背压；精度：0；单位：bar；
        uint32_t n13 : 16; //< 类型：系统；名字：设定13段背压；精度：0；单位：bar；
        uint32_t n14 : 16; //< 类型：系统；名字：设定14段背压；精度：0；单位：bar；
        uint32_t n15 : 16; //< 类型：系统；名字：设定15段背压；精度：0；单位：bar；
        uint32_t n16 : 16; //< 类型：系统；名字：设定16段背压；精度：0；单位：bar；
        uint32_t n17 : 16; //< 类型：系统；名字：设定17段背压；精度：0；单位：bar；
        uint32_t n18 : 16; //< 类型：系统；名字：设定18段背压；精度：0；单位：bar；
        uint32_t n19 : 16; //< 类型：系统；名字：设定19段背压；精度：0；单位：bar；
        uint32_t n20 : 16; //< 类型：系统；名字：设定20段背压；精度：0；单位：bar；
        uint32_t n0 : 16; //< 类型：系统；名字：设定背压最大值；精度：0；单位：bar；
        uint32_t reserve0 : 16; //< 类型：系统；名字：预留；
    } ADJUSTMENT6;

    typedef struct {
        uint32_t min : 10; //< 类型：系统；名字：最小系统压；精度：1；单位：%；
        uint32_t max : 10; //< 类型：系统；名字：最大系统压；精度：1；单位：%；
        uint32_t com : 10; //< 类型：系统；名字：待机系统压；精度：1；单位：%；
        uint32_t ch : 2; //< 类型：系统；名字：系统压通道映射；
    } ADJUSTMENT7;

    typedef struct {
        uint32_t min : 10; //< 类型：系统；名字：最小速度；精度：1；单位：%；
        uint32_t max : 10; //< 类型：系统；名字：最大速度；精度：1；单位：%；
        uint32_t com : 10; //< 类型：系统；名字：待机速度；精度：1；单位：%；
        uint32_t ch : 2; //< 类型：系统；名字：速度通道映射；
    } ADJUSTMENT8;

    typedef struct {
        uint32_t min : 10; //< 类型：系统；名字：最小背压；精度：1；单位：%；
        uint32_t max : 10; //< 类型：系统；名字：最大背压；精度：1；单位：%；
        uint32_t com : 10; //< 类型：系统；名字：待机背压；精度：1；单位：%；
        uint32_t ch : 2; //< 类型：系统；名字：背压通道映射；
    } ADJUSTMENT9;

    typedef struct {
        uint32_t n1 : 16; //< 类型：系统；名字：设定1段系统压DA值；
        uint32_t n2 : 16; //< 类型：系统；名字：设定2段系统压DA值；
        uint32_t n3 : 16; //< 类型：系统；名字：设定3段系统压DA值；
        uint32_t n4 : 16; //< 类型：系统；名字：设定4段系统压DA值；
        uint32_t n5 : 16; //< 类型：系统；名字：设定5段系统压DA值；
        uint32_t n6 : 16; //< 类型：系统；名字：设定6段系统压DA值；
        uint32_t n7 : 16; //< 类型：系统；名字：设定7段系统压DA值；
        uint32_t n8 : 16; //< 类型：系统；名字：设定8段系统压DA值；
        uint32_t n9 : 16; //< 类型：系统；名字：设定9段系统压DA值；
        uint32_t n10 : 16; //< 类型：系统；名字：设定10段系统压DA值；
        uint32_t n11 : 16; //< 类型：系统；名字：设定11段系统压DA值；
        uint32_t n12 : 16; //< 类型：系统；名字：设定12段系统压DA值；
        uint32_t n13 : 16; //< 类型：系统；名字：设定13段系统压DA值；
        uint32_t n14 : 16; //< 类型：系统；名字：设定14段系统压DA值；
        uint32_t n15 : 16; //< 类型：系统；名字：设定15段系统压DA值；
        uint32_t n16 : 16; //< 类型：系统；名字：设定16段系统压DA值；
        uint32_t n17 : 16; //< 类型：系统；名字：设定17段系统压DA值；
        uint32_t n18 : 16; //< 类型：系统；名字：设定18段系统压DA值；
        uint32_t n19 : 16; //< 类型：系统；名字：设定19段系统压DA值；
        uint32_t n20 : 16; //< 类型：系统；名字：设定20段系统压DA值；
    } ADJUSTMENT10;

    typedef struct {
        uint32_t n1 : 16; //< 类型：系统；名字：设定1段速度DA值；
        uint32_t n2 : 16; //< 类型：系统；名字：设定2段速度DA值；
        uint32_t n3 : 16; //< 类型：系统；名字：设定3段速度DA值；
        uint32_t n4 : 16; //< 类型：系统；名字：设定4段速度DA值；
        uint32_t n5 : 16; //< 类型：系统；名字：设定5段速度DA值；
        uint32_t n6 : 16; //< 类型：系统；名字：设定6段速度DA值；
        uint32_t n7 : 16; //< 类型：系统；名字：设定7段速度DA值；
        uint32_t n8 : 16; //< 类型：系统；名字：设定8段速度DA值；
        uint32_t n9 : 16; //< 类型：系统；名字：设定9段速度DA值；
        uint32_t n10 : 16; //< 类型：系统；名字：设定10段速度DA值；
        uint32_t n11 : 16; //< 类型：系统；名字：设定11段速度DA值；
        uint32_t n12 : 16; //< 类型：系统；名字：设定12段速度DA值；
        uint32_t n13 : 16; //< 类型：系统；名字：设定13段速度DA值；
        uint32_t n14 : 16; //< 类型：系统；名字：设定14段速度DA值；
        uint32_t n15 : 16; //< 类型：系统；名字：设定15段速度DA值；
        uint32_t n16 : 16; //< 类型：系统；名字：设定16段速度DA值；
        uint32_t n17 : 16; //< 类型：系统；名字：设定17段速度DA值；
        uint32_t n18 : 16; //< 类型：系统；名字：设定18段速度DA值；
        uint32_t n19 : 16; //< 类型：系统；名字：设定19段速度DA值；
        uint32_t n20 : 16; //< 类型：系统；名字：设定20段速度DA值；
    } ADJUSTMENT11;

    typedef struct {
        uint32_t n1 : 16; //< 类型：系统；名字：设定1段背压DA值；
        uint32_t n2 : 16; //< 类型：系统；名字：设定2段背压DA值；
        uint32_t n3 : 16; //< 类型：系统；名字：设定3段背压DA值；
        uint32_t n4 : 16; //< 类型：系统；名字：设定4段背压DA值；
        uint32_t n5 : 16; //< 类型：系统；名字：设定5段背压DA值；
        uint32_t n6 : 16; //< 类型：系统；名字：设定6段背压DA值；
        uint32_t n7 : 16; //< 类型：系统；名字：设定7段背压DA值；
        uint32_t n8 : 16; //< 类型：系统；名字：设定8段背压DA值；
        uint32_t n9 : 16; //< 类型：系统；名字：设定9段背压DA值；
        uint32_t n10 : 16; //< 类型：系统；名字：设定10段背压DA值；
        uint32_t n11 : 16; //< 类型：系统；名字：设定11段背压DA值；
        uint32_t n12 : 16; //< 类型：系统；名字：设定12段背压DA值；
        uint32_t n13 : 16; //< 类型：系统；名字：设定13段背压DA值；
        uint32_t n14 : 16; //< 类型：系统；名字：设定14段背压DA值；
        uint32_t n15 : 16; //< 类型：系统；名字：设定15段背压DA值；
        uint32_t n16 : 16; //< 类型：系统；名字：设定16段背压DA值；
        uint32_t n17 : 16; //< 类型：系统；名字：设定17段背压DA值；
        uint32_t n18 : 16; //< 类型：系统；名字：设定18段背压DA值；
        uint32_t n19 : 16; //< 类型：系统；名字：设定19段背压DA值；
        uint32_t n20 : 16; //< 类型：系统；名字：设定20段背压DA值；
    } ADJUSTMENT12;

    typedef struct {
        uint32_t tp : 16; //< 类型：系统；名字：测试压力；精度：0；单位：bar；
        uint32_t tbp : 16; //< 类型：系统；名字：测试背压；精度：0；单位：bar；
        /**********************/
        uint32_t s0 : 5; //< 类型：系统；名字：设定调整比例阀段数；精度：0；单位：sec；
        uint32_t s1 : 5; //< 类型：系统；名字：压力调整总段数；精度：0；单位：sec；
        uint32_t s2 : 5; //< 类型：系统；名字：速度调整总段数；精度：0；单位：sec；
        uint32_t s3 : 5; //< 类型：系统；名字：背压调整总段数；精度：0；单位：sec；
        uint32_t ts : 8; //< 类型：系统；名字：测试速度；精度：0；单位：%；
        uint32_t item : 2; //< 类型：系统；名字：调整项目；格式：……
        //< + 0-系统压-当前调整项目为系统压……
        //< + 1-速度-当前调整项目为速度……
        //< + 2-背压-当前调整项目为系背压；
        uint32_t reserve0 : 2; //< 类型：系统；名字：预留；
    } ADJUSTMENT13;

    typedef struct {
        uint32_t p0 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p1 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p2 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p3 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p4 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p5 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p6 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p7 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p8 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p9 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p10 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p11 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p12 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p13 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p14 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p15 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p16 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p17 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p18 : 8; //< 类型：系统；名字：速度范围；
        uint32_t p19 : 8; //< 类型：系统；名字：速度范围；
    } ADJUSTMENT19;

    typedef struct {
        uint32_t in0 : 8; //< 类型：系统；名字：第0IO输入口映射；
        uint32_t in1 : 8; //< 类型：系统；名字：第1IO输入口映射；
        uint32_t in2 : 8; //< 类型：系统；名字：第2IO输入口映射；
        uint32_t in3 : 8; //< 类型：系统；名字：第3IO输入口映射；
        uint32_t in4 : 8; //< 类型：系统；名字：第4IO输入口映射；
        uint32_t in5 : 8; //< 类型：系统；名字：第5IO输入口映射；
        uint32_t in6 : 8; //< 类型：系统；名字：第6IO输入口映射；
        uint32_t in7 : 8; //< 类型：系统；名字：第7IO输入口映射；
        uint32_t in8 : 8; //< 类型：系统；名字：第8IO输入口映射；
        uint32_t in9 : 8; //< 类型：系统；名字：第9IO输入口映射；
        uint32_t in10 : 8; //< 类型：系统；名字：第10IO输入口映射；
        uint32_t in11 : 8; //< 类型：系统；名字：第11IO输入口映射；
        uint32_t in12 : 8; //< 类型：系统；名字：第12IO输入口映射；
        uint32_t in13 : 8; //< 类型：系统；名字：第13IO输入口映射；
        uint32_t in14 : 8; //< 类型：系统；名字：第14IO输入口映射；
        uint32_t in15 : 8; //< 类型：系统；名字：第15IO输入口映射；
        uint32_t in16 : 8; //< 类型：系统；名字：第16IO输入口映射；
        uint32_t in17 : 8; //< 类型：系统；名字：第17IO输入口映射；
        uint32_t in18 : 8; //< 类型：系统；名字：第18IO输入口映射；
        uint32_t in19 : 8; //< 类型：系统；名字：第19IO输入口映射；
        uint32_t in20 : 8; //< 类型：系统；名字：第20IO输入口映射；
        uint32_t in21 : 8; //< 类型：系统；名字：第21IO输入口映射；
        uint32_t in22 : 8; //< 类型：系统；名字：第22IO输入口映射；
        uint32_t in23 : 8; //< 类型：系统；名字：第23IO输入口映射；
        uint32_t in24 : 8; //< 类型：系统；名字：第24IO输入口映射；
        uint32_t in25 : 8; //< 类型：系统；名字：第25IO输入口映射；
        uint32_t in26 : 8; //< 类型：系统；名字：第26IO输入口映射；
        uint32_t in27 : 8; //< 类型：系统；名字：第27IO输入口映射；
        uint32_t in28 : 8; //< 类型：系统；名字：第28IO输入口映射；
        uint32_t in29 : 8; //< 类型：系统；名字：第29IO输入口映射；
        uint32_t in30 : 8; //< 类型：系统；名字：第30IO输入口映射；
        uint32_t in31 : 8; //< 类型：系统；名字：第31IO输入口映射；
    } ADJUSTMENT20;

    typedef struct {
        uint32_t in0 : 8; //< 类型：系统；名字：第0IO输出口映射；
        uint32_t in1 : 8; //< 类型：系统；名字：第1IO输出口映射；
        uint32_t in2 : 8; //< 类型：系统；名字：第2IO输出口映射；
        uint32_t in3 : 8; //< 类型：系统；名字：第3IO输出口映射；
        uint32_t in4 : 8; //< 类型：系统；名字：第4IO输出口映射；
        uint32_t in5 : 8; //< 类型：系统；名字：第5IO输出口映射；
        uint32_t in6 : 8; //< 类型：系统；名字：第6IO输出口映射；
        uint32_t in7 : 8; //< 类型：系统；名字：第7IO输出口映射；
        uint32_t in8 : 8; //< 类型：系统；名字：第8IO输出口映射；
        uint32_t in9 : 8; //< 类型：系统；名字：第9IO输出口映射；
        uint32_t in10 : 8; //< 类型：系统；名字：第10IO输出口映射；
        uint32_t in11 : 8; //< 类型：系统；名字：第11IO输出口映射；
        uint32_t in12 : 8; //< 类型：系统；名字：第12IO输出口映射；
        uint32_t in13 : 8; //< 类型：系统；名字：第13IO输出口映射；
        uint32_t in14 : 8; //< 类型：系统；名字：第14IO输出口映射；
        uint32_t in15 : 8; //< 类型：系统；名字：第15IO输出口映射；
        uint32_t in16 : 8; //< 类型：系统；名字：第16IO输出口映射；
        uint32_t in17 : 8; //< 类型：系统；名字：第17IO输出口映射；
        uint32_t in18 : 8; //< 类型：系统；名字：第18IO输出口映射；
        uint32_t in19 : 8; //< 类型：系统；名字：第19IO输出口映射；
        uint32_t in20 : 8; //< 类型：系统；名字：第20IO输出口映射；
        uint32_t in21 : 8; //< 类型：系统；名字：第21IO输出口映射；
        uint32_t in22 : 8; //< 类型：系统；名字：第22IO输出口映射；
        uint32_t in23 : 8; //< 类型：系统；名字：第23IO输出口映射；
        uint32_t in24 : 8; //< 类型：系统；名字：第24IO输出口映射；
        uint32_t in25 : 8; //< 类型：系统；名字：第25IO输出口映射；
        uint32_t in26 : 8; //< 类型：系统；名字：第26IO输出口映射；
        uint32_t in27 : 8; //< 类型：系统；名字：第27IO输出口映射；
        uint32_t in28 : 8; //< 类型：系统；名字：第28IO输出口映射；
        uint32_t in29 : 8; //< 类型：系统；名字：第29IO输出口映射；
        uint32_t in30 : 8; //< 类型：系统；名字：第30IO输出口映射；
        uint32_t in31 : 8; //< 类型：系统；名字：第31IO输出口映射；
        uint32_t in32 : 8; //< 类型：系统；名字：第32IO输出口映射；
        uint32_t in33 : 8; //< 类型：系统；名字：第33IO输出口映射；
        uint32_t in34 : 8; //< 类型：系统；名字：第34IO输出口映射；
        uint32_t in35 : 8; //< 类型：系统；名字：第35IO输出口映射；
        uint32_t in36 : 8; //< 类型：系统；名字：第36IO输出口映射；
        uint32_t in37 : 8; //< 类型：系统；名字：第37IO输出口映射；
        uint32_t in38 : 8; //< 类型：系统；名字：第38IO输出口映射；
        uint32_t in39 : 8; //< 类型：系统；名字：第39IO输出口映射；
    } ADJUSTMENT21;

    typedef struct {
        uint32_t p : 16; //< 类型：模号；名字：限压；精度：0；单位：bar；
        uint32_t s : 16; //< 类型：模号；名字：限速；精度：0；单位：%；
    } ADJUSTMENT22;

    typedef struct {
        uint32_t out0 : 8; //< 类型：系统；名字：第0IO输出口定义；
        uint32_t out1 : 8; //< 类型：系统；名字：第1IO输出口定义；
        uint32_t out2 : 8; //< 类型：系统；名字：第2IO输出口定义；
        uint32_t out3 : 8; //< 类型：系统；名字：第3IO输出口定义；
        uint32_t out4 : 8; //< 类型：系统；名字：第4IO输出口定义；
        uint32_t out5 : 8; //< 类型：系统；名字：第5IO输出口定义；
        uint32_t out6 : 8; //< 类型：系统；名字：第6IO输出口定义；
        uint32_t out7 : 8; //< 类型：系统；名字：第7IO输出口定义；
        uint32_t out8 : 8; //< 类型：系统；名字：第8IO输出口定义；
        uint32_t out9 : 8; //< 类型：系统；名字：第9IO输出口定义；
        uint32_t out10 : 8; //< 类型：系统；名字：第10IO输出口定义；
        uint32_t out11 : 8; //< 类型：系统；名字：第11IO输出口定义；
        uint32_t out12 : 8; //< 类型：系统；名字：第12IO输出口定义；
        uint32_t out13 : 8; //< 类型：系统；名字：第13IO输出口定义；
        uint32_t out14 : 8; //< 类型：系统；名字：第14IO输出口定义；
        uint32_t out15 : 8; //< 类型：系统；名字：第15IO输出口定义；
        uint32_t out16 : 8; //< 类型：系统；名字：第16IO输出口定义；
        uint32_t out17 : 8; //< 类型：系统；名字：第17IO输出口定义；
        uint32_t out18 : 8; //< 类型：系统；名字：第18IO输出口定义；
        uint32_t out19 : 8; //< 类型：系统；名字：第19IO输出口定义；
        uint32_t out20 : 8; //< 类型：系统；名字：第20IO输出口定义；
        uint32_t out21 : 8; //< 类型：系统；名字：第21IO输出口定义；
        uint32_t out22 : 8; //< 类型：系统；名字：第22IO输出口定义；
        uint32_t out23 : 8; //< 类型：系统；名字：第23IO输出口定义；
        uint32_t out24 : 8; //< 类型：系统；名字：第24IO输出口定义；
        uint32_t out25 : 8; //< 类型：系统；名字：第25IO输出口定义；
        uint32_t out26 : 8; //< 类型：系统；名字：第26IO输出口定义；
        uint32_t out27 : 8; //< 类型：系统；名字：第27IO输出口定义；
        uint32_t out28 : 8; //< 类型：系统；名字：第28IO输出口定义；
        uint32_t out29 : 8; //< 类型：系统；名字：第29IO输出口定义；
        uint32_t out30 : 8; //< 类型：系统；名字：第30IO输出口定义；
        uint32_t out31 : 8; //< 类型：系统；名字：第31IO输出口定义；
        uint32_t out32 : 8; //< 类型：系统；名字：第32IO输出口定义；
        uint32_t out33 : 8; //< 类型：系统；名字：第33IO输出口定义；
        uint32_t out34 : 8; //< 类型：系统；名字：第34IO输出口定义；
        uint32_t out35 : 8; //< 类型：系统；名字：第35IO输出口定义；
        uint32_t out36 : 8; //< 类型：系统；名字：第36IO输出口定义；
        uint32_t out37 : 8; //< 类型：系统；名字：第37IO输出口定义；
        uint32_t out38 : 8; //< 类型：系统；名字：第38IO输出口定义；
        uint32_t out39 : 8; //< 类型：系统；名字：第39IO输出口定义；
    } ADJUSTMENT23;

    typedef union {
        ADJUSTMENT0 para;
        uint16_t all_para16[sizeof (ADJUSTMENT0) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT0) / 4];
    } ADJUSTMENT_PARA0;

    typedef union {
        ADJUSTMENT1 para;
        uint16_t all_para16[sizeof (ADJUSTMENT1) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT1) / 4];
    } ADJUSTMENT_PARA1;

    typedef union {
        ADJUSTMENT2 para;
        uint16_t all_para16[sizeof (ADJUSTMENT2) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT2) / 4];
    } ADJUSTMENT_PARA2;

    typedef union {
        ADJUSTMENT3 para;
        uint16_t all_para16[sizeof (ADJUSTMENT3) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT3) / 4];
    } ADJUSTMENT_PARA3;

    typedef union {
        ADJUSTMENT4 para;
        uint16_t all_para16[sizeof (ADJUSTMENT4) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT4) / 4];
    } ADJUSTMENT_PARA4;

    typedef union {
        ADJUSTMENT5 para;
        uint16_t all_para16[sizeof (ADJUSTMENT5) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT5) / 4];
    } ADJUSTMENT_PARA5;

    typedef union {
        ADJUSTMENT6 para;
        uint16_t all_para16[sizeof (ADJUSTMENT6) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT6) / 4];
    } ADJUSTMENT_PARA6;

    typedef union {
        ADJUSTMENT7 para;
        uint16_t all_para16[sizeof (ADJUSTMENT7) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT7) / 4];
    } ADJUSTMENT_PARA7;

    typedef union {
        ADJUSTMENT8 para;
        uint16_t all_para16[sizeof (ADJUSTMENT8) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT8) / 4];
    } ADJUSTMENT_PARA8;

    typedef union {
        ADJUSTMENT9 para;
        uint16_t all_para16[sizeof (ADJUSTMENT9) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT9) / 4];
    } ADJUSTMENT_PARA9;

    typedef union {
        ADJUSTMENT10 para;
        uint16_t all_para16[sizeof (ADJUSTMENT10) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT10) / 4];
    } ADJUSTMENT_PARA10;

    typedef union {
        ADJUSTMENT11 para;
        uint16_t all_para16[sizeof (ADJUSTMENT11) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT11) / 4];
    } ADJUSTMENT_PARA11;

    typedef union {
        ADJUSTMENT12 para;
        uint16_t all_para16[sizeof (ADJUSTMENT12) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT12) / 4];
    } ADJUSTMENT_PARA12;

    typedef union {
        ADJUSTMENT13 para;
        uint16_t all_para16[sizeof (ADJUSTMENT13) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT13) / 4];
    } ADJUSTMENT_PARA13;

    typedef union {

        struct {
            uint32_t sd : 1; //< 类型：系统；名字：安全门关调模；格式：……
            //< + 0-不使用-调模进不需关安全门……
            //< + 1-使用-调模进需要关安全门；
            uint32_t m10 : 1; //< 类型：系统；名字：开关模正负10V输出；格式：……
            //< + 0-不使用-开关模都是0到10V……
            //< + 1-使用-关模是正10V输出，开模是负10V输出；
            uint32_t i10 : 1; //< 类型：系统；名字：射出正负10V输出；格式：……
            //< + 0-不使用-射胶是0到10V……
            //< + 1-使用-射胶是正10V输出，松退是负10V输出；
            uint32_t c10 : 1; //< 类型：系统；名字：加料正负10V输出；格式：……
            //< + 0-不使用-加料是0到10V……
            //< + 1-使用-胶料是负10V输出；
            uint32_t si : 1; //< 类型：系统；名字：安全门开禁止射胶；格式：……
            //< + 0-不使用-安全门开可以射胶……
            //< + 1-使用-安全门开不允许射胶；
            uint32_t sn : 1; //< 类型：系统；名字：安全门开禁止座进；格式：……
            //< + 0-不使用-安全门开可以座进……
            //< + 1-使用-安全门开不允许座进；
            uint32_t m_10 : 1; //< 类型：系统；名字：开关模正负10V输出方向取反；格式：……
            //< + 0-不使用-开关模不变化……
            //< + 1-使用-开关模正负10V输出使用的时候，该选项才有效，效果是相反；
            uint32_t i_10 : 1; //< 类型：系统；名字：射出正负10V输出方向取反；格式：……
            //< + 0-不使用-射出不变化……
            //< + 1-使用-射出正负10V输出使用的时候，该选项才有效，效果是相反；
            uint32_t c_10 : 1; //< 类型：系统；名字：加料正负10V输出方向取反；格式：……
            //< + 0-不使用-加料不变化……
            //< + 1-使用-加料正负10V输出使用的时候，该选项才有效，效果是相反；
            uint32_t so : 1; //< 类型：系统；名字：安全门开禁止开模；格式：……
            //< + 0-不使用-安全门开可以开模……
            //< + 1-使用-安全门开不允许开模；
            uint32_t se : 1; //< 类型：系统；名字：安全门开禁止顶出；格式：……
            //< + 0-不使用-安全门开可以顶出……
            //< + 1-使用-安全门开不允许顶出；
            uint32_t sca : 1; //< 类型：系统；名字：安全门开禁止入芯；格式：……
            //< + 0-不使用-安全门开可以入芯……
            //< + 1-使用-安全门开不允许入芯；
            uint32_t test_robot : 1; //< 类型：系统；名字：机械手联调测试；
            uint32_t scd : 1; //< 类型：系统；名字：安全门开禁止出芯；格式：……
            //< + 0-不使用-安全门开可以出芯……
            //< + 1-使用-安全门开不允许出芯；
            uint32_t s_c : 1; //< 类型：系统；名字：加料动作有松退；
            uint32_t double_oil_way : 1; //< 类型：系统；名字：双油路使能；
            uint32_t turn_safe : 1; //< 类型：系统；名字：安全门开转手动；
            uint32_t use_dp : 1; //< 类型：系统；名字：直压机构使用；
            uint32_t mold_mapping : 2; //< 类型：系统；名字：开关模正负10V映射；
            uint32_t inject_mapping : 2; //< 类型：系统；名字：射出正负10V映射；
            uint32_t charge_mapping : 2; //< 类型：系统；名字：加料正负10V映射；
            uint32_t time : 8; //< 类型：系统；名字：安全门防抖时间；精度：2；单位：s；

        };
        uint32_t all_para;
    } ADJUSTMENT_PARA14;

    typedef union {

        struct {
            uint32_t seg : 10; //< 类型：系统；名字：段数；精度：0；单位：sec；
            uint32_t action : 10; //< 类型：系统；名字：动作；
            uint32_t point : 9; //< 类型：系统；名字：输出点；
            uint32_t en : 1; //< 类型：系统；名字：使能；
            uint32_t mode : 2; //< 类型：系统；名字：模式；
        };
        uint32_t all_para;
    } ADJUSTMENT_PARA15;

    typedef union {

        struct {
            uint32_t io0 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io1 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io2 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io3 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io4 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io5 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io6 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io7 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io8 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io9 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io10 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io11 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io12 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io13 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io14 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
            uint32_t io15 : 2; //< 类型：系统；名字：；格式：……
            //< + 0-不使用-IO点不使用强制功能……
            //< + 1-强制OFF-IO点强制为OFF；
            //< + 2-强制ON-IO点强制为ON；
        };
        uint32_t all_para;
    } ADJUSTMENT_PARA16;

    typedef union {

        struct {
            uint32_t max : 8; //< 类型：系统；名字：泵总数；
            uint32_t seg : 8; //< 类型：系统；名字：泵分段段数；
            uint32_t reserve : 14; //< 类型：系统；名字：预留；
            uint32_t mode : 1; //< 类型：系统；名字：模式；//0为手动，1为自动
            uint32_t en : 1; //< 类型：系统；名字：使能；
        };
        uint32_t all_para;
    } ADJUSTMENT_PARA17; //< 泵功能设定

    typedef union {

        struct {
            uint32_t output_point : 8; //< 类型：系统；名字：输出点；
            uint32_t capacity : 12; //< 类型：系统；名字：泵功率；
            uint32_t pump_select : 12; //< 类型：系统；名字：泵选择；
        };
        uint32_t all_para;
    } ADJUSTMENT_PARA18; //< 组合泵设定

    typedef union {
        ADJUSTMENT19 para;
        uint8_t all_para8[sizeof (ADJUSTMENT19)];
        uint16_t all_para16[sizeof (ADJUSTMENT19) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT19) / 4];
    } ADJUSTMENT_PARA19;

    typedef union {
        ADJUSTMENT20 para;
        uint8_t all_para8[sizeof (ADJUSTMENT20)];
        uint16_t all_para16[sizeof (ADJUSTMENT20) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT20) / 4];
    } ADJUSTMENT_PARA20;

    typedef union {
        ADJUSTMENT21 para;
        uint8_t all_para8[sizeof (ADJUSTMENT21)];
        uint16_t all_para16[sizeof (ADJUSTMENT21) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT21) / 4];
    } ADJUSTMENT_PARA21;

    typedef union {
        ADJUSTMENT22 para;
        uint16_t all_para16[sizeof (ADJUSTMENT22) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT22) / 4];
    } ADJUSTMENT_PARA22;

    typedef union {
        ADJUSTMENT23 para;
        uint8_t all_para8[sizeof (ADJUSTMENT23)];
        uint16_t all_para16[sizeof (ADJUSTMENT23) / 2];
        uint32_t all_para[sizeof (ADJUSTMENT23) / 4];
    } ADJUSTMENT_PARA23;

    //< 调机参数结构
    static const uint32_t adjustment_addr[] = {
        ICAddr_Adjustment_Para500,
        ICAddr_Adjustment_Para699 //<类型：模号；名字：；结构：ADJUSTMENT_PARA；地址：adjustment_addr；
    };

    typedef struct {
        ADJUSTMENT_PARA0 e; //电子尺长度
        ADJUSTMENT_PARA1 oil; //油缸行程
        ADJUSTMENT_PARA2 max; //油缸最大AD值
        ADJUSTMENT_PARA3 min; //油缸最小AD值
        /**********************/
        uint32_t s0 : 1; //< 类型：系统；名字：动模位置感应器；格式：……
        //< + 0-电子尺-动模位置感应器为电子尺……
        //< + 1-近接开关-动模位置感应器为近接开关；
        uint32_t s1 : 1; //< 类型：系统；名字：射出位置感应器；格式：……
        //< + 0-电子尺-射出位置感应器为电子尺……
        //< + 1-旋转编码器-射出位置感应器为旋转编码器；
        uint32_t s2 : 1; //< 类型：系统；名字：座台位置感应器；格式：……
        //< + 0-电子尺-座台位置感应器为电子尺……
        //< + 1-近接开关-座台位置感应器为近接开关；
        uint32_t s3 : 1; //< 类型：系统；名字：顶针位置感应器；格式：……
        //< + 0-电子尺-顶针位置感应器为电子尺……
        //< + 1-近接开关-顶针位置感应器为近接开关；
        uint32_t c0 : 3; //< 类型：系统；名字：动模AD通道；
        uint32_t c1 : 3; //< 类型：系统；名字：射出AD通道；
        uint32_t c2 : 3; //< 类型：系统；名字：座台AD通道；
        uint32_t c3 : 3; //< 类型：系统；名字：顶针AD通道；
        uint32_t new_m : 8; //< 类型：系统；名字：装载新模号；
        uint32_t reserve0 : 8; //< 类型：系统；名字：进入CANOpen调试页面；
        /**********************/
        ADJUSTMENT_PARA13 tp; // 比例阀测试参数2
        ADJUSTMENT_PARA4 p; // 系统压调整设定11
        ADJUSTMENT_PARA10 pv; // 系统压DA值调整设定
        ADJUSTMENT_PARA5 s; // 速度调整设定
        ADJUSTMENT_PARA11 sv; // 速度DA值调整设定
        ADJUSTMENT_PARA6 bp; //背压调整设定
        ADJUSTMENT_PARA12 bpv; // 背压DA值调整设定
        ADJUSTMENT_PARA7 p_da; // 系统压范围
        ADJUSTMENT_PARA8 s_da; // 速度范围
        ADJUSTMENT_PARA9 bp_da; // 背压范围
        /**********************/
        ADJUSTMENT_PARA14 safe; //< 安全功能选项
        /**********************/
        ADJUSTMENT_PARA15 pro[20]; //< 可编程设定
        /**********************/
        ADJUSTMENT_PARA16 in1; //< 类型：系统；名字：X0到X17模拟输入；
        ADJUSTMENT_PARA16 in2; //< 类型：系统；名字：X20到X37模拟输入；
        ADJUSTMENT_PARA16 out1; //< 类型：系统；名字：Y0到Y17模拟输入；
        ADJUSTMENT_PARA16 out2; //< 类型：系统；名字：Y20到Y37模拟输入；
        ADJUSTMENT_PARA16 out3; //< 类型：系统；名字：Y40到Y47模拟输入；
        /**********************/
        ADJUSTMENT_PARA17 pump; //< 泵功能设定
        ADJUSTMENT_PARA18 pu_para[20]; //< 组合参数设定
        ADJUSTMENT_PARA19 pu_p;
        /**********************/
        ADJUSTMENT_PARA20 in; //< 输入口映射；
        ADJUSTMENT_PARA21 out; //< 输出口映射；
        /**********************/
        ADJUSTMENT22 low_l; //< 类型：模号；名字：低压模保；
        ADJUSTMENT22 eje_l; //< 类型：模号；名字：顶针动作；
        ADJUSTMENT22 core_l; //< 类型：模号；名字：抽芯动作；
        ADJUSTMENT22 charge_l; //< 类型：模号；名字：加料动作；
        /**********************/
        ADJUSTMENT_PARA23 od; //< 输出口定义；
        /**********************/
    } ADJUSTMENT_PARA_0;

    typedef union {
        ADJUSTMENT_PARA_0 para;
        uint32_t all_para[sizeof (ADJUSTMENT_PARA_0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_Adjustment_Para500, ICAddr_Adjustment_Para699)];
    } ADJUSTMENT_PARA;
    /******************************************************************************/

    //< 调机参数结构
    static const uint32_t alarm_addr[] = {
        ICAddr_Adjustment_Para700,
        ICAddr_Adjustment_Para999 //<类型：模号；名字：；结构：ALARM_PARA；地址：alarm_addr；
    };

    typedef struct{
        uint32_t en:1;//< 类型：系统；名字：报警使能；
        uint32_t tips:1;//< 类型：系统；名字：提示；
        uint32_t light:1;//< 类型：系统；名字：闪灯；
        uint32_t sound:1;//< 类型：系统；名字：发声；
        uint32_t abnormal:1;//< 类型：系统；名字：触发异常时间倒计时；
        uint32_t manual:1;//< 类型：系统；名字：转手动；
        uint32_t motor:1;//< 类型：系统；名字：停电机；
        uint32_t reserve:25;//< 类型：系统；名字：预留；
    }ALARM_PARA_1;

    typedef struct{
        ALARM_PARA_1 p[256];
    }ALARM_PARA_0;

    typedef union {
        ALARM_PARA_0 para;
        uint32_t all[STRUCE_SIZE(ICAddr_Adjustment_Para700, ICAddr_Adjustment_Para999)];
    } ALARM_PARA;
    /******************************************************************************/

    /******************************************************************************
 系统使用参数
     ******************************************************************************/
    static const uint32_t system_addr[] = {
        ICAddr_System_Para0,
        ICAddr_System_Para49 //<类型：模号；名字：；结构：SYSTEM_PARA；地址：system_addr；
    };

    typedef struct {
        uint32_t p0; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p1; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p2; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p3; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p4; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p5; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p6; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p7; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p8; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p9; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p10; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p11; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p12; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p13; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p14; //< 类型：系统；名字：系统运行参数查询；
        uint32_t p15; //< 类型：系统；名字：系统运行参数查询；
    } SYSTEM_RUN_PARA0;

    typedef union {
        SYSTEM_RUN_PARA0 para;
        uint16_t all_para16[sizeof (SYSTEM_RUN_PARA0) / 2];
        uint32_t all_para[sizeof (SYSTEM_RUN_PARA0) / 4];
    } SYSTEM_RUN_PARA;

    typedef struct {
        /**********************/
        uint32_t test[8]; //< 类型：系统；名字：调试使用；
        /**********************/
        SYSTEM_RUN_PARA run;
        /**********************/
        uint32_t correct_t : 1; //< 类型：系统；名字：室温开始自矫正按钮；
        uint32_t upgrade : 1; //< 类型：系统；名字：升级程序；
        uint32_t page1 : 1; //< 类型：系统；名字：进入比例阀调整页面；
        uint32_t init_end : 1; //< 类型：系统；名字：初始化结束；
        uint32_t reserve0 : 12; //< 类型：系统；名字：预留；
        uint32_t room_t : 16; //< 类型：系统；名字：室温标准测量值输入；
        /**********************/
    } SYSTEM_PARA0;

    typedef union {
        SYSTEM_PARA0 para;
        uint32_t all_para[sizeof (SYSTEM_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_System_Para0, ICAddr_System_Para49)];
    } SYSTEM_PARA;

    /******************************************************************************
     读返回参数
     ******************************************************************************/
    static const uint32_t read_addr[] = {
        ICAddr_Read_Status0,
        ICAddr_Read_Status61 //<类型：模号；名字：；结构：RASD_PARA；地址：read_addr；
    };

    typedef union {

        struct {
            uint32_t pos1; //< 类型：状态；名字：模座电子尺实际位置；精度：2；单位：mm；
            uint32_t pos2; //< 类型：状态；名字：螺杆电子尺实际位置；精度：2；单位：mm；
            uint32_t pos3; //< 类型：状态；名字：座台电子尺实际位置；精度：2；单位：mm；
            uint32_t pos4; //< 类型：状态；名字：顶针电子尺实际位置；精度：2；单位：mm；
            uint32_t pos5; //< 类型：状态；名字：预留电子尺实际位置；精度：2；单位：mm；
            uint32_t pos6; //< 类型：状态；名字：预留电子尺实际位置；精度：2；单位：mm；
        };
        uint32_t all[6];
    } RULER_POS;

    typedef union {

        struct {
            uint32_t adv1; //< 类型：状态；名字：模座电子尺AD值；
            uint32_t adv2; //< 类型：状态；名字：螺杆电子尺AD值；
            uint32_t adv3; //< 类型：状态；名字：座台电子尺AD值；
            uint32_t adv4; //< 类型：状态；名字：顶针电子尺AD值预留；
            uint32_t adv5; //< 类型：状态；名字：预留电子尺AD值；
            uint32_t adv6; //< 类型：状态；名字：预留电子尺AD值；
        };
        uint32_t all[6];
    } RULER_ADV;
    
    typedef union {//<设定压力值(转矩)

        struct {
            uint32_t prset1 :16; //< 类型：状态；名字：电机ID1压力设定值；
            uint32_t prset2 :16; //< 类型：状态；名字：电机ID2压力设定值；
            uint32_t prset3 :16; //< 类型：状态；名字：电机ID3压力设定值；
            uint32_t prset4 :16; //< 类型：状态；名字：电机ID4压力设定值；
            uint32_t prset5 :16; //< 类型：状态；名字：电机ID5压力设定值；
            uint32_t prset6 :16; //< 类型：状态；名字：电机ID6压力设定值；
        };
        uint32_t all[3];
    } PRESS_SET;
    
    typedef union {//<当前压力值(转矩)

        struct {
            uint32_t pract1 :16; //< 类型：状态；名字：电机ID1压力当前值；
            uint32_t pract2 :16; //< 类型：状态；名字：电机ID2压力当前值；
            uint32_t pract3 :16; //< 类型：状态；名字：电机ID3压力当前值；
            uint32_t pract4 :16; //< 类型：状态；名字：电机ID4压力当前值；
            uint32_t pract5 :16; //< 类型：状态；名字：电机ID5压力当前值；
            uint32_t pract6 :16; //< 类型：状态；名字：电机ID6压力当前值；
        };
        uint32_t all[3];
    } PRESS_ACT;
    
    typedef union {//<设定速度值(频率)

        struct {
            uint32_t spset1 :16; //< 类型：状态；名字：电机ID1速度设定值；
            uint32_t spset2 :16; //< 类型：状态；名字：电机ID2速度设定值；
            uint32_t spset3 :16; //< 类型：状态；名字：电机ID3速度设定值；
            uint32_t spset4 :16; //< 类型：状态；名字：电机ID4速度设定值；
            uint32_t spset5 :16; //< 类型：状态；名字：电机ID5速度设定值；
            uint32_t spset6 :16; //< 类型：状态；名字：电机ID6速度设定值；
        };
        uint32_t all[3];
    } SPEED_SET;
    
    typedef union {//<当前速度值(频率)

        struct {
            uint32_t spact1 :16; //< 类型：状态；名字：电机ID1速度当前值；
            uint32_t spact2 :16; //< 类型：状态；名字：电机ID2速度当前值；
            uint32_t spact3 :16; //< 类型：状态；名字：电机ID3速度当前值；
            uint32_t spact4 :16; //< 类型：状态；名字：电机ID4速度当前值；
            uint32_t spact5 :16; //< 类型：状态；名字：电机ID5速度当前值；
            uint32_t spact6 :16; //< 类型：状态；名字：电机ID6速度当前值；
        };
        uint32_t all[3];
    } SPEED_ACT;

    typedef struct {
        uint32_t addr; //< 类型：状态；名字：CAN地址；
        uint32_t value; //< 类型：状态；名字：CAN数据；
    } CAN_PARA;

    typedef union {

        struct {
            uint32_t temp0 : 16; //< 类型：状态；名字：喷嘴实际温度；精度：1；单位：°C；
            uint32_t temp1 : 16; //< 类型：状态；名字：一段实际温度；精度：1；单位：°C；
            uint32_t temp2 : 16; //< 类型：状态；名字：二段实际温度；精度：1；单位：°C；
            uint32_t temp3 : 16; //< 类型：状态；名字：三段实际温度；精度：1；单位：°C；
            uint32_t temp4 : 16; //< 类型：状态；名字：四段实际温度；精度：1；单位：°C；
            uint32_t temp5 : 16; //< 类型：状态；名字：五段实际温度；精度：1；单位：°C；
            uint32_t temp6 : 16; //< 类型：状态；名字：六段实际温度；精度：1；单位：°C；
            uint32_t temp7 : 16; //< 类型：状态；名字：油温实际温度；精度：1；单位：°C；
        };
        uint16_t all[8];
    } TEMP;

    typedef union {

        struct {
            uint32_t addr : 16; //< 类型：状态；名字：动作名字；
            uint32_t time : 16; //< 类型：状态；名字：动作时间；精度：1；单位：s；
        };
        uint32_t all;
    } ACTIOM_TIME;

    typedef struct {
        /**********************/
        uint32_t mode : 4; //< 类型：状态；名字：当前模式；格式：ICSTATUS；
        uint32_t action : 8; //< 类型：状态；名字：当前动作；格式：ICACTTION；
        uint32_t auto_run : 1; //< 类型：状态；名字：自动运行状态；
        uint32_t mold_thickness : 1; //< 类型：状态；名字：调模使用；
        uint32_t auto_mold_adj : 1; //< 类型：状态；名字：自动调模；
        uint32_t heater : 1; //< 类型：状态；名字：电热状态；
        uint32_t h_ouput : 8; //< 类型：状态；名字：加热输出状态；
        uint32_t cycle_end : 1; //< 类型：状态；名字：1为一个完整的自动生产周期到，可以读取记录品质参数,0为未到；
        uint32_t motor : 1; //< 类型：状态；名字：马达运行状态；
        uint32_t lubricate : 1; //< 类型：状态；名字：润滑状态；
        uint32_t reserve0 : 5; //< 类型：状态；名字：预留；
        /*********1*************/
        uint32_t input; //< 类型：状态；名字：当前IO输入的状态；
        uint32_t output1; //< 类型：状态；名字：当前IO输出的状态；
        uint32_t output2; //< 类型：状态；名字：当前IO输出的状态；
        /********3**************/
        RULER_POS pos; //< 位置
        RULER_ADV adv; //< AD值
        /********12**************/
        uint32_t alarm[8]; //< 类型：状态；名字：报警；
        /********8**************/
        PRESS_SET press_set; //< 类型：状态；名字：设定压力；精度：1；单位：bar；
        PRESS_ACT press_act; //< 类型：状态；名字：当前压力；精度：1；单位：bar；
        SPEED_SET speed_set; //< 类型：状态；名字：设定速度；精度：1；单位：%；
        SPEED_ACT speed_act; //< 类型：状态；名字：当前速度；精度：1；单位：%；
       /********12**************/
        uint32_t backpress_set:16; //< 类型：状态；名字：设定背压；精度：1；单位：bar；
        uint32_t backpress_act:16; //< 类型：状态；名字：当前背压；精度：1；单位：bar；
        /********1**************/
        CAN_PARA can; //< 类型：状态；名字：；
        /********2**************/
        TEMP temp; //< 类型：状态；名字：；
        /********4**************/
        uint32_t ptol; //< 类型：状态；名字：生产总数；
        uint32_t good; //< 类型：状态；名字：良品数；
        uint32_t bad; //< 类型：状态；名字：劣品数；
        uint32_t package; //< 类型：状态；名字：装箱模数；
        uint32_t last; //< 类型：状态；名字：上模周期；动作时间；精度：1；单位：s；
        uint32_t ttol; //< 类型：状态；名字：全程计时；动作时间；精度：1；单位：s；
        uint32_t rpm; //< 类型：状态；名字：储料转速；
        uint32_t whole_time; //< 类型：状态；名字：开机总时间；
        uint32_t auto_time; //< 类型：状态；名字：自动生产时间；
        /********9**************/
        ACTIOM_TIME action_time1; //< 类型：状态；名字：；
        ACTIOM_TIME action_time2; //< 类型：状态；名字：；
        /********2**************/
        uint32_t software : 16; //< 类型：状态；名字：软件版本；
        uint32_t hardware : 16; //< 类型：状态；名字：硬件版本；
        /********1**************/
        uint32_t run_addr; //< 类型：状态；名字：运行变量地址；
        uint32_t run_value; //< 类型：状态；名字：运行变量值；
        /*******2***************/
        uint32_t ie : 16; //< 类型：状态；名字：射出终点；精度：1；单位：mm；
        uint32_t ke : 16; //< 类型：状态；名字：保压终点；精度：1；单位：mm；
        uint32_t it : 16; //< 类型：状态；名字：射出时间；精度：1；单位：s；
        uint32_t ce : 16; //< 类型：状态；名字：加料终点；精度：1；单位：mm；
        uint32_t me : 16; //< 类型：状态；名字：开模终点；精度：1；单位：mm；
        uint32_t aciton_2 : 16; //< 类型：状态；名字：双油路动作显示；
        /********3**************/
        uint32_t test[2]; //< 类型：状态；名字：备用或调试用；
        /*******2***************/
    } READ_PARA0;

    typedef union {
        READ_PARA0 para;
        uint32_t all_para[sizeof (READ_PARA0) / 4];
        uint32_t all[STRUCE_SIZE(ICAddr_Read_Status0, ICAddr_Read_Status61)];
    } READ_PARA;

    /*******************************************************************************/
    typedef struct _ALL_PARA_ {
        uint32_t BeginSection; //<保留
        /*********************/
        SYSTEM_PARA sys;
        /*********************/
        uint32_t action; //< 动作
        /*********************/
        MOLD_CLOSE_PARA mc_p; //< 关模动作
        MOLD_OPEN_PARA mo_p; //< 开模动作
        INJECT_IN_PARA i_p; //< 射出动作
        BEFORE_INJECT_CHARGE_PARA bic_p; //< 射前加料动作
        CHARGE_PARA c_p; //< 加料动作
        COOL_PARA co_p; //< 冷却动作
        FRONT_SUCKBACK_PARA bs_p; //< 前松退动作
        AFTER_SUCKBACK_PARA as_p; //< 后松退动作
        EJECT_ADV_PARA ea_p; //< 顶进动作
        EJECT_RET_PARA er_p; //< 顶退动作
        BLOW_PARA air; //< 吹气参数
        ALL_CORE_PARA core; //< 抽芯动作
        NOZZLE_ADV_PARA na_p; //< 座进动作
        NOZZLE_RET_PARA nr_p; //< 座退动作
        MOLD_ADJUST_PARA m_adj; //< 调模参数
        AUTOPURGE_PARA ap_p; //< 自动清料参数
        AUTORUN_PARA ar_p; //< 自动运行
        FOECE_BULICATE_PARA fb_p; //< 润滑参数
        PRODUCT_PARA p_p; //< 生产参数
        ELECTRIC_EYE_PARA eye; //< 电眼功能参数
        MOTOR_PARA motor; //< 马达参数
        TEMPERATURE_PARA t_p; //< 温度参数
        /*********************/
        ADJUSTMENT_PARA ma_p; //< 调机参数
        /*********************/
        ALARM_PARA alarm;//< 警报参数
        /*********************/
        uint32_t can_open[ICAddr_CanOpen_Para1350 - ICAddr_Adjustment_Para999];
        uint32_t reserve[ICAddr_Write_Section_End - ICAddr_CanOpen_Para1350];
        /*********************/
        READ_PARA read;
    } ALL_PARA;

    typedef struct _HEAT_TIMER{
      uint32_t sun_timer_en:1; //< 类型：模号；名字：定时使能；
      uint32_t sun_heat_timer:15; //< 类型：模号；名字：加热定时；
      uint32_t sun_hold_timer:15; //< 类型：模号；名字：保温定时；
      uint32_t sun_timer_res:1; //< 类型：模号；名字：定时预留；
      uint32_t mon_timer_en:1; //< 类型：模号；名字：定时使能；
      uint32_t mon_heat_timer:15; //< 类型：模号；名字：加热定时；
      uint32_t mon_hold_timer:15; //< 类型：模号；名字：保温定时；
      uint32_t mon_timer_res:1; //< 类型：模号；名字：定时预留；
      uint32_t tur_timer_en:1; //< 类型：模号；名字：定时使能；
      uint32_t tur_heat_timer:15; //< 类型：模号；名字：加热定时；
      uint32_t tur_hold_timer:15; //< 类型：模号；名字：保温定时；
      uint32_t tur_timer_res:1; //< 类型：模号；名字：定时预留；
      uint32_t web_timer_en:1; //< 类型：模号；名字：定时使能；
      uint32_t web_heat_timer:15; //< 类型：模号；名字：加热定时；
      uint32_t web_hold_timer:15; //< 类型：模号；名字：保温定时；
      uint32_t web_timer_res:1; //< 类型：模号；名字：定时预留；
      uint32_t thu_timer_en:1; //< 类型：模号；名字：定时使能；
      uint32_t thu_heat_timer:15; //< 类型：模号；名字：加热定时；
      uint32_t thu_hold_timer:15; //< 类型：模号；名字：保温定时；
      uint32_t thu_timer_res:1; //< 类型：模号；名字：定时预留；
      uint32_t fri_timer_en:1; //< 类型：模号；名字：定时使能；
      uint32_t fri_heat_timer:15; //< 类型：模号；名字：加热定时；
      uint32_t fri_hold_timer:15; //< 类型：模号；名字：保温定时；
      uint32_t fri_timer_res:1; //< 类型：模号；名字：定时预留；
      uint32_t sat_timer_en:1; //< 类型：模号；名字：定时使能；
      uint32_t sat_heat_timer:15; //< 类型：模号；名字：加热定时；
      uint32_t sat_hold_timer:15; //< 类型：模号；名字：保温定时；
      uint32_t sat_timer_res:1; //< 类型：模号；名字：定时预留；
    } HEAT_TIMER;

        typedef struct _SAFE_{
            uint32_t all_safe:1; //< 类型：系统；名字：强制安全标准；
            uint32_t reserve0:31; //< 类型：系统；名字：预留；
        }SAFETY_STANDARDS;

#ifdef	__cplusplus
}
#endif

#endif	/* HCCOMMPARAGENERICDEF_H */
