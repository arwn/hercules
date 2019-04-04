/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:02:23 by awindham          #+#    #+#             */
/*   Updated: 2019/03/28 23:02:25 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_H
# define U_H

# define L1 const char usage[] = "usage: ./a.out [-p port] [-s string]" ;int
# define L2 L1 main(int argc, char *argv[]){ int listenfd, connfd, port, c = 0;
# define L3 L2 struct sockaddr_in serv_addr; char *buf = 0; while((c =
# define L4 L3 getopt(argc, argv, "p:s:" )) != -1) switch(c){ case 'p': port =
# define L5 L4 atoi(optarg); break; case 's': buf = optarg; break; default:
# define L6 L5 puts(usage); exit(1); } if(buf == 0) buf = "pong pong" ; if(port
# define L7 L6 == 0) port = 2020; listenfd = socket(AF_INET, SOCK_STREAM, 0);
# define L8 L7 serv_addr.sin_family = AF_INET; serv_addr.sin_addr.s_addr =
# define L9 L8 htonl(INADDR_ANY); serv_addr.sin_port = htons(port);
# define LA L9 bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
# define LB LA listen(listenfd, 10); printf(
# define LC LB "starting server on port %d, with string '%s'\n" , port, buf);
# define LD LC fflush(0); while(1) { connfd = accept(listenfd, (struct
# define LE LD sockaddr*)NULL, NULL); dprintf(connfd, "%s\n" , buf);
# define LF LE close(connfd); sleep(1); }}
# define FUN LF

#endif
