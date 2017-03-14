#ifndef _wsd_observer_h
#define _wsd_observer_h

#include "message.h"

typedef struct wsd_Observer wsd_Observer;

typedef void (*wsd_cb_on_chunk)(void *receiver, wsd_Chunk *payload);
typedef void (*wsd_cb_on_close)(void *receiver, int code, wsd_Chunk *reason);
typedef void (*wsd_cb_on_error)(void *receiver, int code, char *reason);
typedef void (*wsd_cb_on_message)(void *receiver, wsd_Message *message);

wsd_Observer *  wsd_Observer_create(void *receiver,
                                    wsd_cb_on_error on_error,
                                    wsd_cb_on_message on_message,
                                    wsd_cb_on_close on_close,
                                    wsd_cb_on_chunk on_ping,
                                    wsd_cb_on_chunk on_pong);

void            wsd_Observer_destroy(wsd_Observer *observer);
void            wsd_Observer_on_error(wsd_Observer *observer, int code, char *reason);
void            wsd_Observer_on_message(wsd_Observer *observer, wsd_Message *message);
void            wsd_Observer_on_close(wsd_Observer *observer, int code, wsd_Chunk *reason);
void            wsd_Observer_on_ping(wsd_Observer *observer, wsd_Chunk *payload);
void            wsd_Observer_on_pong(wsd_Observer *observer, wsd_Chunk *payload);

#endif
