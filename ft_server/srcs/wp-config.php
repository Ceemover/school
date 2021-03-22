<?php
 /**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'new_database' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '?PlEto6gJ+)$3JtXKR+/MY]_#.LCfJ){k9ZP V{ 7:e1K`8_]z&Er}A]_gN*L4W)');
define('SECURE_AUTH_KEY',  'orJ/<+g1mO2<?WxhrY<kTwRu?ruG=ahw_~Z3En:vNYuP4RZu^`q-qWUvzj7@qSkT');
define('LOGGED_IN_KEY',    '&fOkpGF-K0</%IPsy++Q+,w,)[486GuyKF>UXpOad#Gu5`qmH*kx`Fq&E+r&a9l6');
define('NONCE_KEY',        '<:NL]4 e%?kg2$8 !s/@oNiuw8H5Vvuw-z6x.c00.(ZZ]bi=VWIEqh& Rme{tsG~');
define('AUTH_SALT',        ')&}hBl,r3]x<R)fTQxE#d!hg#Xf`5LyIv;?tGC@&I*AP5I1|rU/4^;;%(0p=et]0');
define('SECURE_AUTH_SALT', 'Kdi_;6V85(IQ@@.a0/uJySI>gGyDb[OCaLB+%@NJ?e&Wg{gvf%P|IwJc=|x{Bc-+');
define('LOGGED_IN_SALT',   '-Yi+Vp+ L&%|.n=0CtQ<af13&VU+u`;]bbCz$NM4YuF?Di4nk+UEuR#bk[):1&fL');
define('NONCE_SALT',       '`J=7H`rK92_FWw%xkjs>P5)Q(g8u+UNhS0#,|qtrU]wc.eWu>G<Zx?N&{%4eZ[w5');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
