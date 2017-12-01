// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const addon = require('bindings')('addon');
const point_template = (hp, index) => `
    <div class="list-group-item list-group-item-action flex-column align-items-start">
        <div class="d-flex w-100 justify-content-between">
            <div>${hp.leftAngle.degree}˚${hp.leftAngle.minutes}''${hp.leftAngle.seconds}'</div>
            <small class="hp_remove" data-index="${index}">remove</small>
        </div>
        <div>${hp.rightAngle.degree}˚${hp.rightAngle.minutes}''${hp.rightAngle.seconds}'</div>
        <div>${hp.rightDistance} ft.</div>
    </div>
    `;

var horizontalPoints = [];

function removePoint() {
    var index = parseInt($(this).data("index"));
    horizontalPoints.splice(index, 1);
    updatePointsList();
}

function updatePointsList() {
    $('#points').html(horizontalPoints.map(point_template).join(''));
    $('.hp_remove').on('click', removePoint);
    $('#points').css('display', horizontalPoints.length == 0 ? 'none' : 'block');
    $("#solve").prop('disabled', horizontalPoints.length == 0);
}

$("#newPointAdd").click(function() {
    var horizontalPoint = {
        leftAngle: {
            degree: $("#azimuth_ld").val(),
            minutes: $("#azimuth_lm").val(),
            seconds: $("#azimuth_ls").val()
        },
        rightAngle: {
            degree: $("#azimuth_rd").val(),
            minutes: $("#azimuth_rm").val(),
            seconds: $("#azimuth_rs").val()
        },
        rightDistance: $("#distance_r").val()
    };
    horizontalPoints.push(horizontalPoint);
    updatePointsList();
    $('#newPoint').modal('toggle');
})

$('#newPoint').on('hidden.bs.modal', function () {
    $("#azimuth_ld").val("");
    $("#azimuth_lm").val("");
    $("#azimuth_ls").val("");
    $("#azimuth_rd").val("");
    $("#azimuth_rm").val("");
    $("#azimuth_rs").val("");
    $("#distance_r").val("");
})

$("#solve").click(function() {
    var point = {
        x: $("#a_x").val(),
        y: $("#a_y").val()
    }
    var azimuth = {
        degree: $("#azimuth_d").val(),
        minutes: $("#azimuth_m").val(),
        seconds: $("#azimuth_s").val()
    }
    var solution = addon.traverse(point, azimuth, horizontalPoints);

    $("#solution").text(solution);
})
