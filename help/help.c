/*
  Copyright(C) 2015 Masafumi Yokoyama <yokoyama@clear-code.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 2.1 as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <string.h>

#include <groonga/plugin.h>

static grn_obj *
command_help(grn_ctx *ctx, int nargs, grn_obj **args, grn_user_data *user_data)
{
  if (0) {
    grn_ctx_output_bool(ctx, GRN_TRUE);
  } else {
    grn_ctx_output_bool(ctx, GRN_FALSE);
  }
  return NULL;
}

static grn_obj *
command_default_encoding(grn_ctx *ctx, int nargs, grn_obj **args, grn_user_data *user_data)
{
  grn_ctx_output_cstr(ctx, grn_encoding_to_string(grn_get_default_encoding()));
  return NULL;
}

grn_rc
GRN_PLUGIN_INIT(grn_ctx *ctx)
{
  return GRN_SUCCESS;
}

grn_rc
GRN_PLUGIN_REGISTER(grn_ctx *ctx)
{
  grn_expr_var vars[0];

  grn_plugin_command_create(ctx, "help", -1, command_help, 0, vars);
  grn_plugin_command_create(ctx, "default_encoding", -1, command_default_encoding, 0, vars);

  return ctx->rc;
}

grn_rc
GRN_PLUGIN_FIN(grn_ctx *ctx)
{
  return GRN_SUCCESS;
}
