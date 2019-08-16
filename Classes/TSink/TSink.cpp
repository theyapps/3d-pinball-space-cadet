#include "../../pinball.h"

//----- (01017130) --------------------------------------------------------
void __stdcall TSink::TimerExpired(int a1, void *a2)
{
int v2; // eax

v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)((char *)a2 + 30) + 262) + 8);
*(_DWORD *)(v2 + 106) = 0;
*(_BYTE *)(v2 + 5) = 1;
*(_DWORD *)(v2 + 42) = *(_DWORD *)((char *)a2 + 86);
*(_DWORD *)(v2 + 46) = *(_DWORD *)((char *)a2 + 90);
throw_ball(
(struct TBall *)v2,
(struct vector_type *)((char *)a2 + 98),
*(float *)((char *)a2 + 110),
*(float *)((char *)a2 + 114),
*(float *)((char *)a2 + 118));
if ( *(_DWORD *)((char *)a2 + 126) )
loader_play_sound(*(_DWORD *)((char *)a2 + 126));
*(_DWORD *)((char *)a2 + 78) = 0;
}

//----- (01017197) --------------------------------------------------------
int __thiscall TSink::Message(TSink *this, int a2, float a3)
{
TSink *v3; // esi
int v4; // eax
int v5; // ecx
_DWORD *v6; // eax

v3 = this;
switch ( a2 )
{
case 56:
if ( a3 < 0.0 )
a3 = *(float *)((char *)this + 82);
*(_DWORD *)((char *)this + 78) = timer_set(a3, (int)this, (int)TSink::TimerExpired);
break;
case 1020:
*(_DWORD *)((char *)this + 4 * *(_DWORD *)(*(_DWORD *)((char *)this + 30) + 218) + 142) = *(_DWORD *)((char *)this + 6);
*(_DWORD *)((char *)this + 6) = *(_DWORD *)((char *)this + 4 * (unsigned __int64)(signed __int64)_floor(a3) + 142);
break;
case 1024:
if ( *(_DWORD *)((char *)this + 78) )
timer_kill(*(_DWORD *)((char *)this + 78));
v4 = *(_DWORD *)((char *)v3 + 30);
*(_DWORD *)((char *)v3 + 78) = 0;
*(_DWORD *)((char *)v3 + 6) = 0;
v5 = 0;
if ( *(_DWORD *)(v4 + 214) > 0 )
{
v6 = (_DWORD *)((char *)v3 + 142);
do
{
*v6 = 0;
++v5;
++v6;
}
while ( v5 < *(_DWORD *)(*(_DWORD *)((char *)v3 + 30) + 214) );
}
break;
}
return 0;
}

//----- (01017262) --------------------------------------------------------
int __thiscall TSink::get_scoring(TSink *this, int a2)
{
int result; // eax

if ( a2 >= 3 )
result = 0;
else
result = *(_DWORD *)((char *)this + 4 * a2 + 130);
return result;
}

//----- (01017283) --------------------------------------------------------
void __thiscall TSink::put_scoring(TSink *this, int a2, int a3)
{
if ( a2 < 3 )
*(_DWORD *)((char *)this + 4 * a2 + 130) = a3;
}

//----- (010184ED) --------------------------------------------------------
void __thiscall TSink::Collision(TSink *this, struct TBall *a2, struct vector_type *a3, struct vector_type *a4, float a5, struct TEdgeSegment *a6)
{
TSink *v6; // esi
int v7; // eax
_DWORD *v8; // ST14_4

v6 = this;
v7 = *(_DWORD *)((char *)this + 30);
*(_DWORD *)((char *)this + 78) = 0;
if ( *(_DWORD *)(v7 + 370) )
{
basic_collision(a2, a3, a4, *(float *)((char *)this + 54), *(float *)((char *)this + 58), 1000000000.0, 0.0);
}
else
{
v8 = *(_DWORD **)((char *)a2 + 26);
*((_BYTE *)a2 + 5) = 0;
render_sprite_set_bitmap(v8, 0);
loader_play_sound(*(_DWORD *)((char *)v6 + 122));
control_handler(63, v6);
}
}

//----- (0101A416) --------------------------------------------------------
TSink *__thiscall TSink::TSink(TSink *this, struct TPinballTable *a2, int a3)
{
TSink *v3; // ebx
int v4; // eax
int v5; // eax
int v6; // eax
_DWORD *v7; // eax
char v9; // [esp+Ch] [ebp-48h]
int v10; // [esp+24h] [ebp-30h]
float v11; // [esp+28h] [ebp-2Ch]
int v12; // [esp+2Ch] [ebp-28h]
int v13; // [esp+30h] [ebp-24h]
int v14; // [esp+34h] [ebp-20h]
int v15; // [esp+38h] [ebp-1Ch]
int v16; // [esp+44h] [ebp-10h]
int v17; // [esp+48h] [ebp-Ch]

v3 = this;
TCollisionComponent::TCollisionComponent(this, a2, a3, 1);
*(_DWORD *)v3 = &TSink::`vftable';
*(_DWORD *)((char *)v3 + 6) = 0;
*(_DWORD *)((char *)v3 + 78) = 0;
loader_query_visual(a3, 0, &v9);
v4 = v15;
*(float *)((char *)v3 + 118) = v11 * 0.01;
*(_DWORD *)((char *)v3 + 98) = v12;
*(_DWORD *)((char *)v3 + 110) = v4;
*(_DWORD *)((char *)v3 + 114) = v10;
v5 = v16;
*(_DWORD *)((char *)v3 + 102) = v13;
*(_DWORD *)((char *)v3 + 122) = v5;
v6 = v17;
*(_DWORD *)((char *)v3 + 106) = v14;
*(_DWORD *)((char *)v3 + 126) = v6;
v7 = (_DWORD *)loader_query_float_attribute(a3, 0, 601);
*(_DWORD *)((char *)v3 + 86) = *v7;
*(_DWORD *)((char *)v3 + 90) = v7[1];
*(_DWORD *)((char *)v3 + 82) = *(_DWORD *)loader_query_float_attribute(a3, 0, 407);
return v3;
}
// 1002704: using guessed type void *TSink::`vftable';
