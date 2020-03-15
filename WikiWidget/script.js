var myURL = "https://en.wikipedia.org/w/api.php?action=opensearch&callback=?&suggest=true&search=";

function searchWiki(){
    myURL += $('#searchbox').val();
    $.getJSON(myURL, function(json){
        if(json[1][0]===undefined) { $('.search-results').html('<span class="no-results col-xs-12 text-center">No results found.</span>'); }
        else {
            var list = [];
            $.each(json[1], function(i){
                list[i] = '<td><a href="' + json[3][i] + '">' + json[1][i] + '</a></td><td>' + json[2][i] + '</td>';
            });
            $.each(list, function(i){
                $('tbody').append('<tr id="result-' + i + '" class="result">');
                $('#result-' + i).html(list[i]);
                $('tbody').append('</tr>');
            });
        }
    });
    myURL = "https://en.wikipedia.org/w/api.php?action=opensearch&callback=?&search=";

}

$(document).ready(function(){

    $('#search').on('click', function(){
       $('.search-container').toggleClass('hidden');
       $('.search-results').toggleClass('hidden');
    });


    $('#submit').on('click', function(){
        searchWiki();
    });

    $('input').keyup(function(k){
        if(k.keyCode == 13){
            searchWiki();
        }
    });

});
