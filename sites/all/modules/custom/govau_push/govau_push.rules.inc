<?php

/**
 * Implement hook_rules_action_info().
 */
function govau_push_rules_action_info()
{

    return array(
        'govau_push_rules_action_remote_post' => array(
            'label' => t('Post form/node content to GOV.AU'),
            'group' => t('Custom'),
            'parameter' => array(
                'nid' => array(
                    'type' => 'text',
                    'label' => t('Node ID'),
                    'description' => t('Enter a value'),
                ),

                'sid' => array(
                    'type' => 'text',
                    'label' => t('Submission ID'),
                    'description' => t('Enter a value'),
                )
            ),

            'provides' => array(
                'result' => array(
                    'type' => 'text',
                    'label' => t('Submission Result'),
                ),
            ),
            'callback' => 'govau_push_rules_action_remote_post',
        ),
    );
}

function govau_push_rules_action_remote_post($nid)
{

    $string = "";

    $node = node_load($nid);

    submit_key_value(
        drupal_json_encode(
            json_encode_objects(
                [node_export_prepare_node($node)]
            )
            [0]
        )
    );

    return array(
        'result' => $string,
    );
}
