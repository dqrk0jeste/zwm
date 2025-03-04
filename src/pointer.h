#pragma once

#include <wlr/types/wlr_input_device.h>
#include <wlr/types/wlr_pointer.h>
#include <libinput.h>

struct mwc_pointer {
  struct wlr_pointer *wlr_pointer;
  const char *name;
  struct wl_list link;

  struct wl_listener destroy;
};

enum mwc_cursor_mode {
	MWC_CURSOR_PASSTHROUGH,
	MWC_CURSOR_MOVE,
	MWC_CURSOR_RESIZE,
};

void
server_handle_new_pointer(struct wlr_input_device *device);

void
pointer_handle_destroy(struct wl_listener *listener, void *data);

bool
pointer_configure(struct mwc_pointer *pointer);

void
server_reset_cursor_mode(void);

void
cursor_handle_motion(uint32_t time);

void
server_handle_cursor_motion(struct wl_listener *listener, void *data);

void
server_handle_cursor_motion_absolute(struct wl_listener *listener, void *data);

void
server_handle_cursor_button(struct wl_listener *listener, void *data);

void
server_handle_cursor_axis(struct wl_listener *listener, void *data);

void
server_handle_cursor_frame(struct wl_listener *listener, void *data);
