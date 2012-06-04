<?php
/**
 * @file
 * hapus_rules_configurations.rules_defaults.inc
 */

/**
 * Implementation of hook_default_rules_configuration().
 */
function hapus_rules_configurations_default_rules_configuration() {
  $items = array();
  $items['rules_assign_freemium_role'] = entity_import('rules_config', '{ "rules_assign_freemium_role" : {
      "LABEL" : "Assign freemium role and populate user profile object on sign up",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "TAGS" : [ "Beta_role_assignment" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "user_insert" ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } },
        { "entity_create" : {
            "USING" : {
              "type" : "profile2",
              "param_type" : "main",
              "param_user" : [ "account" ]
            },
            "PROVIDE" : { "entity_created" : { "current_user_profile" : "Created entity" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_role",
              "value" : [ "account:roles" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "applied_role" : "Fetched entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "current-user-profile:field-user-pdf-size-limit" ],
            "value" : {
              "select" : "applied-role:0:nid",
              "php" : { "code" : "$plan = entity_load(\\u0027node\\u0027, array($value));\\r\\n$plan = $plan[$value];\\r\\nreturn $plan-\\u003Efield_single_pdf_size_limit[$plan-\\u003Elanguage][0][\\u0027value\\u0027];" }
            }
          }
        },
        { "data_set" : {
            "data" : [ "current-user-profile:field-user-monthly-limit" ],
            "value" : {
              "select" : "applied-role:0:nid",
              "php" : { "code" : "$plan = entity_load(\\u0027node\\u0027, array($value));\\r\\n$plan = $plan[$value];\\r\\nreturn $plan-\\u003Efield_monthly_limit[$plan-\\u003Elanguage][0][\\u0027value\\u0027];" }
            }
          }
        },
        { "data_set" : {
            "data" : [ "current-user-profile:field-user-monthly-cost" ],
            "value" : {
              "select" : "applied-role:0:nid",
              "php" : { "code" : "$plan = entity_load(\\u0027node\\u0027, array($value));\\r\\n$plan = $plan[$value];\\r\\nreturn $plan-\\u003Efield_cost[$plan-\\u003Elanguage][0][\\u0027value\\u0027];" }
            }
          }
        }
      ]
    }
  }');
  $items['rules_redirect_post_login'] = entity_import('rules_config', '{ "rules_redirect_post_login" : {
      "LABEL" : "Redirect the user after login to user\\/dashboard",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "DO" : [ { "redirect" : { "url" : "user\\/dashboard" } } ]
    }
  }');
  return $items;
}
