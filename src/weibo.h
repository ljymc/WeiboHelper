/*
 * weibo.h
 *
 *  Created on: 2013年8月6日
 *      Author: yeso
 *  		QQ:	272288813
 *		e-mail: cheng@yeso.me
 *		version:	0.1
 */

#ifndef WEIBO_H_
#define WEIBO_H_

#include <curl/curl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



#define WEIBO_POST_URL 			"https://api.weibo.com/2/statuses/update.json"
#define WEIBO_UPLOAD_URL 		"https://upload.api.weibo.com/2/statuses/upload.json"
#define WEIBO_GET_NEWEST_URL 	"https://api.weibo.com/2/statuses/mentions.json"
#define WEIBO_GET_UNREAD_URL 	"https://rm.api.weibo.com/2/remind/unread_count.json"
#define WEIBO_POST_COMMENT_URL 	"https://api.weibo.com/2/comments/create.json"
#define WEIBO_REPOST_URL		"https://api.weibo.com/2/statuses/repost.json"
#define WEIBO_REMIND_RESET_URL	"https://rm.api.weibo.com/2/remind/set_count.json"
#define WEIBO_ACCESS_TOKEN_URL	"https://api.weibo.com/oauth2/access_token"

typedef long long int64;
#define SUCCESS 0
#define FAULT 1

/*
 * 发送一条新微博
 */
int new_weibo_post(const char* access_token,const char* content);

/*
 * //发送一条带图片的微博
 */
int new_weibo_post_upload(const char* access_token,const char* content,const char* picture_file_name);

/*
 * 获取最新的@用户的自己所关注的人的微博(原创)
 * since_id:若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
 * count:单页返回的记录条数，最大不超过200，默认为20。
 */
int get_newest_at_user(const char* access_token,long long since_id,int count,char* result);


/*
 * 评论一条微博
 */
int new_comments_post(const char* access_token,const char* comments,int64 id);


/*
 * 转发微博/转发微博同时评论
 */
int repost_weibo(const char* access_token,const char* comments,int64 id,int iscomment);


/*
 * 获取某个用户的各种消息未读数
 * type:
 * 	status			int		新微博未读数
	follower		int		新粉丝数
	cmt				int		新评论数
	dm				int		新私信数
	mention_status	int		新提及我的微博数
	mention_cmt		int		新提及我的评论数
	group			int		微群消息未读数
	private_group	int		私有微群消息未读数
	notice			int		新通知未读数
	invite			int		新邀请未读数
	badge			int		新勋章数
	photo			int		相册消息未读数
 */
int get_unread_count(const char* access_token,char* result);

/*
 * 对当前登录用户某一种消息未读数进行清零
 * type:
 * mention_status：新提及我的微博数、mention_cmt：新提及我的评论数
 * cmt：新评论数
 */
int remind_reset(const char* access_token,const char* type);

//通过用户名和密码获取到Token，只适用用拥有高权限的APPID
/*例如
 *Weico Android:	appid:211160679 	appsecret:63b64d531b98c2dbff2443816f274dd3
 */
int get_token(const char* appid,const char* appsecret,const char* username,const char* password);

//void debug(const char *fmt, ...);

#endif /* WEIBO_H_ */

