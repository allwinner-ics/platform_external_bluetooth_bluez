/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2010  Nokia Corporation
 *  Copyright (C) 2010  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* GATT Profile Attribute types */
#define GATT_PRIM_SVC_UUID		0x2800
#define GATT_SND_SVC_UUID		0x2801
#define GATT_INCLUDE_UUID		0x2802
#define GATT_CHARAC_UUID		0x2803

/* GATT Characteristic Types */
#define GATT_CHARAC_DEVICE_NAME			0x2A00
#define GATT_CHARAC_APPEARANCE			0x2A01
#define GATT_CHARAC_PERIPHERAL_PRIV_FLAG	0x2A02
#define GATT_CHARAC_RECONNECTION_ADDRESS	0x2A03
#define GATT_CHARAC_PERIPHERAL_PREF_CONN	0x2A04
#define GATT_CHARAC_SERVICE_CHANGED		0x2A05

/* GATT Characteristic Descriptors */
#define GATT_CHARAC_EXT_PROPER_UUID	0x2900
#define GATT_CHARAC_USER_DESC_UUID	0x2901
#define GATT_CLIENT_CHARAC_CFG_UUID	0x2902
#define GATT_SERVER_CHARAC_CFG_UUID	0x2903
#define GATT_CHARAC_FMT_UUID		0x2904
#define GATT_CHARAC_AGREG_FMT_UUID	0x2905

/* Attribute Protocol Opcodes */
#define ATT_OP_ERROR			0x01
#define ATT_OP_MTU_REQ			0x02
#define ATT_OP_MTU_RESP			0x03
#define ATT_OP_FIND_INFO_REQ		0x04
#define ATT_OP_FIND_INFO_RESP		0x05
#define ATT_OP_FIND_BY_TYPE_REQ		0x06
#define ATT_OP_FIND_BY_TYPE_RESP	0x07
#define ATT_OP_READ_BY_TYPE_REQ		0x08
#define ATT_OP_READ_BY_TYPE_RESP	0x09
#define ATT_OP_READ_REQ			0x0A
#define ATT_OP_READ_RESP		0x0B
#define ATT_OP_READ_BLOB_REQ		0x0C
#define ATT_OP_READ_BLOB_RESP		0x0D
#define ATT_OP_READ_MULTI_REQ		0x0E
#define ATT_OP_READ_MULTI_RESP		0x0F
#define ATT_OP_READ_BY_GROUP_REQ	0x10
#define ATT_OP_READ_BY_GROUP_RESP	0x11
#define ATT_OP_WRITE_REQ		0x12
#define ATT_OP_WRITE_RESP		0x13
#define ATT_OP_WRITE_CMD		0x52
#define ATT_OP_PREP_WRITE_REQ		0x16
#define ATT_OP_PREP_WRITE_RESP		0x17
#define ATT_OP_EXEC_WRITE_REQ		0x18
#define ATT_OP_EXEC_WRITE_RESP		0x19
#define ATT_OP_HANDLE_NOTIFY		0x1B
#define ATT_OP_HANDLE_IND		0x1D
#define ATT_OP_HANDLE_CNF		0x1E
#define ATT_OP_SIGNED_WRITE_CMD		0xD2

/* Error codes for Error response PDU */
#define ATT_ECODE_INVALID_HANDLE		0x01
#define ATT_ECODE_READ_NOT_PERM			0x02
#define ATT_ECODE_WRITE_NOT_PERM		0x03
#define ATT_ECODE_INVALID_PDU			0x04
#define ATT_ECODE_INSUFF_AUTHEN			0x05
#define ATT_ECODE_REQ_NOT_SUPP			0x06
#define ATT_ECODE_INVALID_OFFSET		0x07
#define ATT_ECODE_INSUFF_AUTHO			0x08
#define ATT_ECODE_PREP_QUEUE_FULL		0x09
#define ATT_ECODE_ATTR_NOT_FOUND		0x0A
#define ATT_ECODE_ATTR_NOT_LONG			0x0B
#define ATT_ECODE_INSUFF_ENCR_KEY_SIZE		0x0C
#define ATT_ECODE_INVAL_ATTR_VALUE_LEN		0x0D
#define ATT_ECODE_UNLIKELY			0x0E
#define ATT_ECODE_INSUFF_ENC			0x0F
#define ATT_ECODE_UNSUPP_GRP_TYPE		0x10
#define ATT_ECODE_INSUFF_RESOURCES		0x11
/* Application error */
#define ATT_ECODE_IO				0xFF

/* Characteristic Property bit field */
#define ATT_CHAR_PROPER_BROADCAST		0x01
#define ATT_CHAR_PROPER_READ			0x02
#define ATT_CHAR_PROPER_WRITE_WITHOUT_RESP	0x04
#define ATT_CHAR_PROPER_WRITE			0x08
#define ATT_CHAR_PROPER_NOTIFY			0x10
#define ATT_CHAR_PROPER_INDICATE		0x20
#define ATT_CHAR_PROPER_AUTH			0x40
#define ATT_CHAR_PROPER_EXT_PROPER		0x80


#define ATT_MAX_MTU				256
#define ATT_DEFAULT_MTU				23

struct attribute {
	uint16_t handle;
	uuid_t uuid;
	int len;
	uint8_t data[0];
};

struct att_data_list {
	uint16_t num;
	uint16_t len;
	uint8_t **data;
};

/* These functions do byte conversion */
static inline uint8_t att_get_u8(const void *ptr)
{
	const uint8_t *u8_ptr = ptr;
	return bt_get_unaligned(u8_ptr);
}

static inline uint16_t att_get_u16(const void *ptr)
{
	const uint16_t *u16_ptr = ptr;
	return btohs(bt_get_unaligned(u16_ptr));
}

static inline uint32_t att_get_u32(const void *ptr)
{
	const uint32_t *u32_ptr = ptr;
	return btohl(bt_get_unaligned(u32_ptr));
}

static inline void att_put_u8(uint8_t src, void *dst)
{
	bt_put_unaligned(src, (uint8_t *) dst);
}

static inline void att_put_u16(uint16_t src, void *dst)
{
	bt_put_unaligned(htobs(src), (uint16_t *) dst);
}

static inline void att_put_u32(uint16_t src, void *dst)
{
	bt_put_unaligned(htobl(src), (uint32_t *) dst);
}

void att_data_list_free(struct att_data_list *list);

const char *att_ecode2str(uint8_t status);
uint16_t enc_read_by_grp_req(uint16_t start, uint16_t end, uuid_t *uuid,
							uint8_t *pdu, int len);
uint16_t dec_read_by_grp_req(const uint8_t *pdu, int len, uint16_t *start,
						uint16_t *end, uuid_t *uuid);
uint16_t enc_read_by_grp_resp(struct att_data_list *list, uint8_t *pdu, int len);
uint16_t enc_find_by_type_req(uint16_t start, uint16_t end, uuid_t *uuid,
			const uint8_t *value, int vlen, uint8_t *pdu, int len);
uint16_t dec_find_by_type_req(const uint8_t *pdu, int len, uint16_t *start,
		uint16_t *end, uuid_t *uuid, uint8_t *value, int *vlen);
struct att_data_list *dec_read_by_grp_resp(const uint8_t *pdu, int len);
uint16_t enc_read_by_type_req(uint16_t start, uint16_t end, uuid_t *uuid,
							uint8_t *pdu, int len);
uint16_t dec_read_by_type_req(const uint8_t *pdu, int len, uint16_t *start,
						uint16_t *end, uuid_t *uuid);
uint16_t enc_read_by_type_resp(struct att_data_list *list, uint8_t *pdu,
								int len);
uint16_t enc_write_cmd(uint16_t handle, const uint8_t *value, int vlen,
							uint8_t *pdu, int len);
uint16_t dec_write_cmd(const uint8_t *pdu, int len, uint16_t *handle,
						uint8_t *value, int *vlen);
struct att_data_list *dec_read_by_type_resp(const uint8_t *pdu, int len);
uint16_t enc_write_req(uint16_t handle, const uint8_t *value, int vlen,
							uint8_t *pdu, int len);
uint16_t dec_write_req(const uint8_t *pdu, int len, uint16_t *handle,
						uint8_t *value, int *vlen);
uint16_t enc_read_req(uint16_t handle, uint8_t *pdu, int len);
uint16_t dec_read_req(const uint8_t *pdu, int len, uint16_t *handle);
uint16_t enc_read_resp(uint8_t *value, int vlen, uint8_t *pdu, int len);
uint16_t dec_read_resp(const uint8_t *pdu, int len, uint8_t *value, int *vlen);
uint16_t enc_error_resp(uint8_t opcode, uint16_t handle, uint8_t status,
							uint8_t *pdu, int len);
uint16_t enc_find_info_req(uint16_t start, uint16_t end, uint8_t *pdu, int len);
uint16_t dec_find_info_req(const uint8_t *pdu, int len, uint16_t *start,
								uint16_t *end);
uint16_t enc_find_info_resp(uint8_t format, struct att_data_list *list,
							uint8_t *pdu, int len);
struct att_data_list *dec_find_info_resp(const uint8_t *pdu, int len,
							uint8_t *format);
uint16_t enc_notification(struct attribute *a, uint8_t *pdu, int len);
uint16_t enc_indication(struct attribute *a, uint8_t *pdu, int len);
struct attribute *dec_indication(const uint8_t *pdu, int len);
uint16_t enc_confirmation(uint8_t *pdu, int len);

uint16_t enc_mtu_req(uint16_t mtu, uint8_t *pdu, int len);
uint16_t dec_mtu_req(const uint8_t *pdu, int len, uint16_t *mtu);
uint16_t enc_mtu_resp(uint16_t mtu, uint8_t *pdu, int len);
uint16_t dec_mtu_resp(const uint8_t *pdu, int len, uint16_t *mtu);
