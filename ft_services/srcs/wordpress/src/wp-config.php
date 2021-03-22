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
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

$_SERVER['HTTPS'] = 'off';

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'dbolg' );

/** MySQL database password */
define( 'DB_PASSWORD', '12345' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-service:3306' );

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
define('AUTH_KEY',         're.4X?1#Qs,P4|<>#H:|>96q-)tA&k^5t#my6*@*kOnNoM;q[6#-qeLjO`&.5bWJ');
define('SECURE_AUTH_KEY',  'l{l:(h.hqz*ePAb.G+D.@oW6.CIwf7`m|?pbHX%/1x}jIkCF5<6^yuh_x{/k+^{$');
define('LOGGED_IN_KEY',    '#PhLq!JR 7ww`1I>Q sT+-4T}^S2!!d|jnN2KG-niQS@N`ePNMd_m}^@C<]LH-C/');
define('NONCE_KEY',        'o*!%jl3B@E LJf&SLz(:SwoQ^k4 e{aW+en4=2]Rpz4bz:3)f-MXR$6dZaoI?)!(');
define('AUTH_SALT',        'Ihzt+j=G`6xTrw|=~l4CaYW?&=YEI;M(GYRIiPERgK&<xLIY@TTNl_H. |OQ~T]J');
define('SECURE_AUTH_SALT', ')(|E23IiFQ&u }sWajka$[=^u>Qy%v|UN=?H,^+bCxkd~>+~x,Scg@TM!B2&K%Y(');
define('LOGGED_IN_SALT',   'hFMq|WvgUcZif&sK@SjZ6UG6}y5-YY:%X11+)XdR|OE1,^uZu<rzR;w?Lm3cXUGB');
define('NONCE_SALT',       '~z+fW$~C3dL|:`^Q Qj|YFg80EVD!z_a@No3qgy&exlL(OTG2/=3l1WuX?UlgIr.');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wordpress_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', enable );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
