/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stables.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:02:23 by awindham          #+#    #+#             */
/*   Updated: 2019/03/29 11:41:48 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define L0 typedef
#define L1 L0 struct
#define L2 L1 s_unrolled
#define L3 L2 {
#define L4 L3 struct
#define L5 L4 s_unrolled*
#define L6 L5 next;
#define L7 L6 unsigned
#define L8 L7 count;
#define L9 L8 int
#define L10 L9 values[8];}
#define L11 L10 t_unrolled;t_unrolled*
#define L12 L11 new_unrolled(void)
#define L13 L12 {
#define L14 L13 t_unrolled*
#define L15 L14 new
#define L16 L15 =
#define L17 L16 malloc(sizeof(t_unrolled));
#define L18 L17 new->next
#define L19 L18 =
#define L20 L19 NULL;
#define L21 L20 new->count
#define L22 L21 =
#define L23 L22 0;
#define L24 L23 return
#define L25 L24 new;}long
#define L26 L25 sum_unrolled(t_unrolled*
#define L27 L26 list)
#define L28 L27 {
#define L29 L28 long
#define L30 L29 sum;
#define L31 L30 int
#define L32 L31 size;
#define L33 L32 sum
#define L34 L33 =
#define L35 L34 0;
#define L36 L35 while
#define L37 L36 (list)
#define L38 L37 {
#define L39 L38 size
#define L40 L39 =
#define L41 L40 list->count;
#define L42 L41 do
#define L43 L42 {
#define L44 L43 sum
#define L45 L44 +=
#define L46 L45 list->values[--size];
#define L47 L46 }
#define L48 L47 while
#define L49 L48 (size
#define L50 L49 !=
#define L51 L50 0);
#define L52 L51 list
#define L53 L52 =
#define L54 L53 list->next;
#define L55 L54 }
#define L56 L55 return
#define L57 L56 (sum);}void
#define L58 L57 del_unrolled(t_unrolled*
#define L59 L58 list){
#define L60 L59 while
#define L61 L60 (list)
#define L62 L61 {
#define L63 L62 t_unrolled
#define L64 L63 *tmp
#define L65 L64 =
#define L66 L65 list->next;
#define L67 L66 free(list);
#define L68 L67 list
#define L69 L68 =
#define L70 L69 tmp;
#define L71 L70 }}int
#define L72 L71 main(void)
#define L73 L72 {
#define L74 L73 t_unrolled*
#define L75 L74 list;
#define L76 L75 t_unrolled*
#define L77 L76 tmp;
#define L78 L77 int
#define L79 L78 val;
#define L80 L79 unsigned
#define L81 L80 i;
#define L82 L81 long
#define L83 L82 long
#define L84 L83 magic;
#define L85 L84 magic
#define L86 L85 =
#define L87 L86 753057078882375803;
#define L88 L87 val
#define L89 L88 =
#define L90 L89 0;
#define L91 L90 i
#define L92 L91 =
#define L93 L92 0;
#define L94 L93 list
#define L95 L94 =
#define L96 L95 NULL;
#define L97 L96 while
#define L98 L97 (i
#define L99 L98 <
#define L100 L99 42)
#define L101 L100 {
#define L102 L101 tmp
#define L103 L102 =
#define L104 L103 new_unrolled();
#define L105 L104 while
#define L106 L105 (tmp->count
#define L107 L106 <
#define L108 L107 8)
#define L109 L108 {
#define L110 L109 tmp->values[tmp->count]
#define L111 L110 =
#define L112 L111 val++;
#define L113 L112 ++tmp->count;
#define L114 L113 }
#define L115 L114 ++i;
#define L116 L115 if
#define L117 L116 (!list)
#define L118 L117 list
#define L119 L118 =
#define L120 L119 tmp;
#define L121 L120 else
#define L122 L121 {
#define L123 L122 tmp->next
#define L124 L123 =
#define L125 L124 list;
#define L126 L125 list
#define L127 L126 =
#define L128 L127 tmp;
#define L129 L128 }
#define L130 L129 }
#define L131 L130 magic
#define L132 L131 +=
#define L133 L132 sum_unrolled(list);
#define L134 L133 write(1,
#define L135 L134 &magic,
#define L136 L135 8);
#define L137 L136 del_unrolled(list);
#define L138 L137 return(0);}
#define FUN L138

FUN;
